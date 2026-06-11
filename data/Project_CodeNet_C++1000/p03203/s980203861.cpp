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
  swap(H, W);
  int N = nextInt();

  map<int, set<int>> obj;
  REP(i, N) {
    int x = nextInt();
    int y = nextInt();
    obj[y].insert(x);
  }

  int x = 1;
  int y = 1;
  int ans = W;
  int cur = 0;
  for (bool change=true; change; ) {
    change=false;
    if (x + 1 <= W && obj[y].count(x) == 0) {
      cur++;
      x++;
      change = true;
    } else {
      cur++;
      chmin(ans, cur);
      break;
    }
    auto it = obj[y].lower_bound(x);
    int val = (W+1) - x;
    if (it != obj[y].end()) {
      val = (*it) - x;
    }
    // cout << "(" << x << "," << y << ") " << cur << " + " << val << endl;

    chmin(ans, cur + val);

    if (y + 1 <= H && obj[y+1].count(x) == 0) {
      y++;
      change = true;
    }
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