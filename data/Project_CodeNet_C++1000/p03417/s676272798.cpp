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
  
  int n,m;
  cin >> n >> m;
  ll res = 0;
  if(n == 1 && m == 1){
    res = 1;
  }else if(n == 1 || m == 1){
    res = 1ll*n*m-2;
  }else{
    n -= 2;
    m -= 2;
    res = 1ll*n*m;
  }
  cout << res << endl;


  return 0;
}