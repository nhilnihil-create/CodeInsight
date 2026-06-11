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
#define INF (1 << 29)
#define MOD 1000000007
//int dx[4] = {1,0,0,-1};
//int dy[4] = {0,1,-1,0};

bool is_prime(int n){
  for(int i = 2;i*i <= n;i++){
    if(!(n % i))return false;
  }
  return true;
}

int main(){
  
  int n;
  cin >> n;
  vector<int> v;
  for(int i = 11;i < 55555;i++){ 
    if(is_prime(i) && i % 5 == 1)v.push_back(i);
    if(v.size() == n)break;
  }


  for(auto au : v)cout << au << " ";

  return 0;
}
