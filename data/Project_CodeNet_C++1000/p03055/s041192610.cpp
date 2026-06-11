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
vector<int> g[MAX_N];
bool grundy[MAX_N];

pair<int,int> dfs(int cur, int prev) {
  pair<int,int> res = {0, cur};
  for (int nxt : g[cur]) if (nxt != prev) {
    auto p = dfs(nxt, cur);
    p.first++;
    if (res.first < p.first) {
      res = p;
    }
  }
  return res;
}

int main2() {
  REP(i, MAX_N) g[i].clear();
  int N = nextInt();
  REP(i, N-1) {
    int a = nextInt() - 1;
    int b = nextInt() - 1;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  auto p1 = dfs(0, -1);
  auto p2 = dfs(p1.second, -1);

  if (grundy[p2.first + 1]) {
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
  }
  return 0;
}

int main() {
  grundy[0] = 0;
  grundy[1] = 1;
  grundy[2] = 0;
  for (int i = 3; i < MAX_N; i++) {
    grundy[i] = (grundy[i-1] == 0 || grundy[i-2] == 0) ? 1 : 0;
  }
#ifdef LOCAL
  for (;!cin.eof();cin>>ws)
#endif
    main2();
  return 0;
}
