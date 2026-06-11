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

int main2() {
  int N; cin >> N;
  string S; cin >> S;
  int Q; cin >> Q;
  vector<int> ks(Q);
  REP(i, Q) cin >> ks[i];

  for (int k : ks) {
    ll ans = 0;
    ll D = 0;
    ll M = 0;
    ll co = 0;
    REP(i, N) {
      if (i-k >= 0) {
        if (S[i-k] == 'D') {
          D--;
          co -= M;
        } else if (S[i-k] == 'M') {
          M--;
        }
      }

      if (S[i] == 'D') {
        D++;
      }
      else if (S[i] == 'M') {
        M++;
        co += D;
      }
      else if (S[i] == 'C') {
        ans += co;
      }
    }
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
