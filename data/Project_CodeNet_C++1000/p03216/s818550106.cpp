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

ll nextLong() { ll x; scanf("%lld", &x); return x;}

ll solve(const string S, const int K) {
  const int N = S.size();

  ll D = 0, M = 0, C = 0;
  ll ans = 0;

  for (int i = 0; i < N; i++) {
    if (i - K >= 0) {
      if (S[i-K] == 'D') {
        D--;
        C -= M;
      } else if (S[i-K] == 'M') {
        M--;
      }
    }

    if (S[i] == 'D') {
      D++;
    } else if (S[i] == 'M') {
      M++;
      C += D;
    } else if (S[i] == 'C') {
      ans += C;
    }
  }
  return ans;
}

int main2() {
  int N = nextLong();
  string S; cin >> S;
  int Q = nextLong();
  while (Q--) {
    int K = nextLong();
    ll ans = solve(S, K);
    cout << ans << endl;
  }
  return 0;
}

int main() {

#ifdef LOCAL
  for (;!cin.eof();cin>>ws)
#endif
    main2();
  return 0;
}