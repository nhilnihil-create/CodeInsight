#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
#define REP(i,n) for(ll i = 0;i < (ll)n;i++)
#define REPD(i,n) for(ll i = (ll)n - 1;i >= 0;i--)
#define ALL(x) (x).begin(),(x).end()
#define FILLl(n,first_dimension_size,value) fill((ll*)n,(ll*)(n+first_dimension_size),value)
#define FILL(n,first_dimension_size,value) fill((int*)n,(int*)(n+first_dimension_size),value)
#define INF (1 << 30)
#define MOD 1000000007
//int dy[4] = {-1,0,0,1};
//int dx[4] = {0,1,-1,0};



int main(){

  int x,y,z,k;
  cin >> x >> y >> z >> k;
  vector<ll> a(x),b(y),c(z);
  REP(i,x)cin >> a[i];
  REP(i,y)cin >> b[i];
  REP(i,z)cin >> c[i];
  vector<ll> ab;
  REP(i,x)REP(j,y)ab.push_back(a[i]+b[j]);
  sort(ALL(ab),greater<ll>());
  vector<ll> abc;
  REP(i,min(k,x*y))REP(j,z)abc.push_back(ab[i]+c[j]);
  sort(ALL(abc),greater<ll>());
  REP(i,k)cout << abc[i] << endl;


  

  return 0;
}
