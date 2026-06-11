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


int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int X,Y,Z,K;
  cin >> X >> Y >> Z >> K;
  vector<ll> A(X),B(Y),C(Z);
  rep(i,X)  cin >> A.at(i);
  rep(i,Y)  cin >> B.at(i);
  rep(i,Z)  cin >> C.at(i);
  sort(all(A));
  sort(all(B));
  sort(all(C));
  reverse(all(A));
  reverse(all(B));
  reverse(all(C));

  set<tuple<int,int,int>> S;
  priority_queue<pair<ll,tuple<int,int,int>>> pq;
  S.insert(make_tuple(0,0,0));
  pq.push(m_p(A.at(0)+B.at(0)+C.at(0),make_tuple(0,0,0)));
  while(K>0){
    K--;
    cout << pq.top().fi << endl;
    int a,b,c;
    tie(a,b,c)=pq.top().se;
    pq.pop();

    if(a+1<X && !S.count(make_tuple(a+1,b,c))){
      S.insert(make_tuple(a+1,b,c));
      pq.push(m_p(A.at(a+1)+B.at(b)+C.at(c),make_tuple(a+1,b,c)));
    }
    if(b+1<Y && !S.count(make_tuple(a,b+1,c))){
      S.insert(make_tuple(a,b+1,c));
      pq.push(m_p(A.at(a)+B.at(b+1)+C.at(c),make_tuple(a,b+1,c)));
    }
    if(c+1<Z && !S.count(make_tuple(a,b,c+1))){
      S.insert(make_tuple(a,b,c+1));
      pq.push(m_p(A.at(a)+B.at(b)+C.at(c+1),make_tuple(a,b,c+1)));
    }
  }

  return 0;
}