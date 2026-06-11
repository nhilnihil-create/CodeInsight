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

const int MAX_N = 1005;
const int MAX_S = 21234;
struct Item{
  int w, s, v;
};
Item item[MAX_N];

ll dp[MAX_N][MAX_S];

int main2() {
  int N = nextInt();
  REP(i, N) {
    int w = nextInt();
    int s = nextInt();
    int v = nextInt();
    item[i] = {w, s, v};
  }
  sort(item, item + N, [](const Item&a, const Item&b) -> bool {
    return a.w+a.s < b.w+b.s;
  });
  // REP(i, N) {
    // cout << item[i].w << " " << item[i].s << " " << item[i].v << endl;
  // }
  CLR(dp, 0);
  REP(i, N) {
    REP(w, MAX_S) chmax(dp[i+1][w], dp[i][w]);
    REP(w, item[i].s + 1) {
      chmax(dp[i+1][w + item[i].w], dp[i][w] + item[i].v);
    }
  }
  ll ans = 0;
  REP(s, MAX_S) chmax(ans, dp[N][s]);
  cout << ans << endl;
  return 0;
}

int main() {
  for (;!cin.eof();cin>>ws)
    main2();
  return 0;
}
