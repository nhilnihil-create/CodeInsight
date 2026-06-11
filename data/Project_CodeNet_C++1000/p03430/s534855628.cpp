#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i,n) for(int i=0,_n=(int)(n);i<_n;++i)
#define ALL(v) (v).begin(),(v).end()
#define CLR(t,v) memset(t,(v),sizeof(t))
template<class T1,class T2>ostream& operator<<(ostream& os,const pair<T1,T2>&a){return os<<"("<<a.first<<","<<a.second<< ")";}
template<class T>void pv(T a,T b){for(T i=a;i!=b;++i)cout<<(*i)<<" ";cout<<endl;}
template<class T>void chmin(T&a,const T&b){if(a>b)a=b;}
template<class T>void chmax(T&a,const T&b){if(a<b)a=b;}


const int INF = 1001001001;
int dp[303][303][303];

int main2() {
  string s;
  cin >> s;
  int N = (int)s.size();
  int K; cin >> K;
  REP(i, N+1) REP(j, N+1) REP(k, N+1) dp[i][j][k] = -INF;
  REP(i, N) dp[i][i][0] = 0;
  REP(i, N) dp[i][i+1][0] = 1;
  for (int d = 2; d <= N; d++) {
    for (int i = 0; i + d <= N; i++) {
      for (int k = 0; k <= N; k++) {
        int j = i + d;
        chmax(dp[i][j][k], dp[i+1][j][k]);
        chmax(dp[i][j][k], dp[i][j-1][k]);
        if (s[i] == s[j-1]) {
          chmax(dp[i][j][k], dp[i+1][j-1][k] + 2);
        } else {
          chmax(dp[i][j][k+1], dp[i+1][j-1][k] + 2);
        }
      }
    }
  }
  int ans = 0;
  REP(i, N) for (int j = i + 1; j <= N; j++) REP(k, K+1) chmax(ans, dp[i][j][k]);
  cout << ans << endl;
  return 0;
}

int main() {
  for (;!cin.eof();cin>>ws)
    main2();
  return 0;
}
