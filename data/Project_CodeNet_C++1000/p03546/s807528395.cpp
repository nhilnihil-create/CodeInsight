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


int t[10][10];

int main2() {
  int R = nextLong();
  int C = nextLong();

  REP(i, 10) REP(j, 10) t[i][j] = nextLong();

  REP(k, 10) REP(i, 10) REP(j, 10) {
    chmin(t[i][j], t[i][k] + t[k][j]);
  }

  ll ans = 0;
  REP(i, R) REP(j, C) {
    int a = nextLong();
    if (a != -1)
      ans += t[a][1];
  }

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