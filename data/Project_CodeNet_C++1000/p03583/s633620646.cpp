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

int main2() {
  ll N = nextLong();
  for (ll a = 1; a <= 3500; a++) {
    for (ll b = 1; b <= 3500; b++) {

      ll P = N*a*b;
      ll Q = 4*a*b - N*(a+b);
      if (Q != 0 && P % Q == 0 && P / Q > 0) {
        ll c = P / Q;
        cout << a << ' ' << b << ' ' << c << endl;
        return 0;
      }

    }
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