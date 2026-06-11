#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define DUMP(x)  cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define IFOR(i, m, n) for(ll i = n - 1; i >= m; i-- )
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

void yes(){
  cout << "YES" << endl;
  exit(0);
}

void no(){
  cout << "NO" << endl;
  exit(0);
}

int main(){
  vector<vector<ll>> g(4, vector<ll>(4,0));
  REP(i,3){
    ll a,b; cin >> a >> b;
    a--; b--;
    g[a][b] = 1;
    g[b][a] = 1;
  }

  vector<ll> p = {0,1,2,3};
  do{
    REP(i,3){
      if(!g[p[i]][p[i+1]]) break;
      if(i==2) yes();
    }
  }while(next_permutation(ALL(p)));
  no();
}