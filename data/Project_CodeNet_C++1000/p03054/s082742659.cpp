#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define fi first
#define se second
#define m_p make_pair
#define p_b push_back
#define e_b emplace_back
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())

#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)

#ifdef LOCAL//compile with -DLOCAL
#define debug(x) cerr<<"LINE"<<__LINE__<<" : "<<#x<<" = "<<(x)<<endl
#define debug_vec(x) cerr<<"LINE"<<__LINE__<<" : "<<#x<<" = ";\
  rep(i,sz(x)){cerr<<x[i]<<" ";}cerr<<endl
#define debug_mat(x) cerr<<"LINE"<<__LINE__<<" : "<<#x<<" = "<<endl;\
  rep(i,sz(x)){rep(j,sz(x[i])){cerr<<x[i][j]<<" ";}cerr<<endl;}cerr<<endl
#else
#define debug(x) void(0)
#define debug_vec(x) void(0)
#define debug_mat(x) void(0)
#endif

template<class T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<class T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

int N;
bool solve(vector<int> &taka,vector<int> &aoki,int W,int s){
  int l=1;
  int r=W;
  rep(i,N){
    int x=aoki.at(i);
    if(x==1)  r=min(W,r+1);
    if(x==-1) l=max(1,l-1);

    x=taka.at(i);
    if(x==1)  l++;
    if(x==-1) r--;

    if(l>W || r<=0) return false;
    if(r<l) return false;
  }
  if(l<=s && s<=r)  return true;
  else  return false;
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int H,W;
  cin >> H >> W >> N;
  int sy,sx;
  cin >> sy >> sx;
  string S,T;
  cin >> S >> T;

  vector<int> taka1(N,0);
  vector<int> taka2(N,0);
  vector<int> aoki1(N,0);
  vector<int> aoki2(N,0);
  for(int i=N-1;i>=0;i--){
    if(S.at(i)=='L')  taka1.at(N-1-i)=1;
    if(S.at(i)=='R')  taka1.at(N-1-i)=-1;
    if(S.at(i)=='U')  taka2.at(N-1-i)=1;
    if(S.at(i)=='D')  taka2.at(N-1-i)=-1;
    if(T.at(i)=='L')  aoki1.at(N-1-i)=1;
    if(T.at(i)=='R')  aoki1.at(N-1-i)=-1;
    if(T.at(i)=='U')  aoki2.at(N-1-i)=1;
    if(T.at(i)=='D')  aoki2.at(N-1-i)=-1;
  }
  if(solve(taka1,aoki1,W,sx) && solve(taka2,aoki2,H,sy))  cout << "YES" << endl;
  else  cout << "NO" << endl;

  return 0;
}