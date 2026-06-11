#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define SZ(x) ((int)(x).size())
#define rep(i,n) for(int i=0;i<(n);++i)
#define fore(i,a) for(auto &i:a)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;
#define ALL(x) (x).begin(),(x).end()
signed _main(); signed main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> using v = vector<T>;
template<class T> using vv = vector<v<T>>;
const int MOD=1e9+7;
const long long INF = 1LL << 60;
using P=pair<int,int>;

signed _main(){
  int N,K; cin >> N >> K;
  string S; cin >> S;
  v<int> b,w;
  int ans=0;
  int wcnt=0,bcnt=0;
  if(S[0]=='0') w.push_back(0);
  rep(i,N){
    if(S[i]=='0'){
      if(wcnt!=0){
        w.push_back(wcnt);
        wcnt=0;
      }
      bcnt++;
    }
    else{
      if(bcnt!=0){
        b.push_back(bcnt);
        bcnt=0;
      }
      wcnt++;
    }
  }
  if(wcnt!=0){
    w.push_back(wcnt);
    wcnt=0;
  }
  if(bcnt!=0){
    b.push_back(bcnt);
    bcnt=0;
  }
  if(S[SZ(S)-1]=='0') w.push_back(0);
  if(SZ(b)==0){
    cout << w[0] << endl;
    return 0;
  }
  //fore(i,w) cout << i << endl;
  chmin(K,SZ(b));
  for(int i=0;i<SZ(b);i++){
    if(i+K>SZ(b)) break;
    int tmp=0;
    for(int j=i;j<i+K;j++){
      tmp+=b[j];
    }
    for(int j=i;j<i+K+1;j++){
      tmp+=w[j];
    }
    //cout << tmp << endl;
    chmax(ans,tmp);
  }
  cout << ans << endl;
  return 0;
}
