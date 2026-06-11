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

int main2() {
  REP(i, MAX_N) g[i].clear();

  int N = nextInt();
  int M = nextInt();
  string s; cin >> s;

  set< pair<int,int> > vis;

  vector<int> degA(N), degB(N);
  REP(i, M) {
    int a = nextInt() - 1;
    int b = nextInt() - 1;
    if (a > b) swap(a, b);
    if (vis.count({a, b})) continue;
    g[a].push_back(b);
    g[b].push_back(a);
    if (s[b] == 'A') degA[a]++; else degB[a]++;
    if (a != b) {
      if (s[a] == 'A') degA[b]++; else degB[b]++;
    }
  }

  vector<int> dead(N);
  queue<int> q;
  REP(i, N) {
    if (degA[i] == 0 || degB[i] == 0) {
      q.push(i);
      dead[i] = true;
    }
  }
  for (;!q.empty();) {
    int v = q.front(); q.pop();
    for (int u : g[v]) if (!dead[u]) {
      if (s[v] == 'A') {
        if (--degA[u] == 0) {
          dead[u] = true;
          q.push(u);
        }
      } else {
        if (--degB[u] == 0) {
          dead[u] = true;
          q.push(u);
        }
      }
    }
  }

  bool yes = false;
  REP(i, N) if (!dead[i]) yes = true;
  cout << (yes ? "Yes" : "No") << endl;
  return 0;
}

int main() {

#ifdef LOCAL
  for (;!cin.eof();cin>>ws)
#endif
    main2();
  return 0;
}