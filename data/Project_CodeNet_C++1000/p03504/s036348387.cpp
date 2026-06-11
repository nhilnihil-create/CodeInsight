#include<bits/stdc++.h>

using namespace std;
using ll = long long;
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

  int n,c;
  cin >> n >> c;
  vector<int> v(200200,0);
  vector<vector<int>> cc(c,vector<int>(200200,0));
  REP(i,n){
    int l,r,ccc;cin >> l >> r >> ccc;
    ccc--;
    if(cc[ccc][l*2] != -1)cc[ccc][l*2-1]++;
    else cc[ccc][l*2] = 0;
    if(cc[ccc][r*2-1] != 1)cc[ccc][r*2]--;
    else cc[ccc][r*2-1] = 0;
  }
  REP(i,200200)REP(j,c)v[i] += cc[j][i];
  for(int i = 1;i <= 200000;i++)v[i] += v[i-1];
  cout << *max_element(ALL(v)) << endl;











  return 0;
}