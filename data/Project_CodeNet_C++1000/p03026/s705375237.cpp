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
  int N = nextLong();

  vector<vector<int>> g(N);
  REP(i, N-1) {
    int a = nextLong() - 1;
    int b = nextLong() - 1;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<ll> ans(N);
  vector<ll> c(N);
  REP(i, N) c[i] = nextLong();
  sort(ALL(c));

  vector<int> deg(N);
  REP(i, N) deg[i] = g[i].size();

  queue<int> q;
  REP(i, N) {
    if (deg[i] == 1) {
      q.push(i);
    }
  }

  int ci = 0;
  while (!q.empty()) {
    int v = q.front(); q.pop();
    // cout << "v=" << v << endl;
    ans[v] = c[ci++];
    for (int u : g[v]) {
      deg[u]--;
      if (deg[u] == 1) {
        q.push(u);
      }
    }
  }

  ll score = 0;
  REP(u, N) {
    for(int v : g[u]) if (u < v) {
      score += min(ans[u], ans[v]);
    }
  }
  cout << score << endl;
  REP(i, ans.size()) {
    if (i) cout << " ";
    cout << ans[i];
  }
  cout << endl;
  return 0;
}

int main() {

#ifdef LOCAL
  for (;!cin.eof();cin>>ws)
#endif
    main2();
  return 0;
}