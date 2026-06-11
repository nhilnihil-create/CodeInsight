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

int main2() {
  int H = nextInt();
  int W = nextInt();
  int D = nextInt();

  pair<int,int> p[H*W + 1];
  REP(h, H) REP(w, W) {
    int x = nextInt();
    p[x] = {h, w};
  }

  vector<ll> acc(H*W+10);
  for (int i = 1; i <= H*W; i++) {
    if (i - D <= 0) {
      acc[i] = 0;
    } else {
      acc[i] = acc[i - D] + abs(p[i-D].first - p[i].first) + abs(p[i-D].second - p[i].second);
    }
  }

  // REP(i, H*W) cout << p[i+1] << endl;
  // REP(i, H*W) cout << acc[i+1] << endl;


  int Q = nextInt();
  REP(_, Q) {
    int from = nextInt();
    int to = nextInt();

    // int ans = 0;
    // while (from != to) {
    //   ans += abs(p[from].first - p[from + D].first) + abs(p[from].second - p[from + D].second);
    //   from += D;
    // }
    int ans = acc[to] - acc[max(0, from)];
    printf("%d\n", ans);
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