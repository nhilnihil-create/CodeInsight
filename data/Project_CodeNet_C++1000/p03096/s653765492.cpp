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

int nextInt() { int x; scanf("%d", &x); return x;}
ll nextLong() { ll x; scanf("%lld", &x); return x;}

const int MAX_N = 212345;
const ll MOD = (ll)(1e9 + 7);
int C[MAX_N];
int L[MAX_N];
int B[MAX_N];
ll dp[MAX_N];

int main2() {
  CLR(L, -1);
  CLR(B, 0);
  CLR(dp, 0);

  int N = nextInt();
  REP(i, N) C[i] = nextInt();
  REP(i, N) {
    B[i] = L[C[i]];
    L[C[i]] = i;
  }

  dp[0] = 1;
  for (int i = 1; i < N; i++) {
    dp[i] = dp[i-1];
    int j = B[i];
    if (j != -1 && j != i-1) {
      dp[i] += dp[j];
    }
    dp[i] %= MOD;
  }
  ll ans = dp[N-1];
  cout << ans << endl;
  return 0;
}

int main() {

#ifdef LOCAL
  for (;!cin.eof();cin>>ws)
#endif
    main2();
  return 0;
}
