#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define FILLl(n,first_dimension_size,value) fill((ll*)n,(ll*)(n+first_dimension_size),value)
#define FILL(n,first_dimension_size,value) fill((int*)n,(int*)(n+first_dimension_size),value)
#define INF (1 << 30)
#define MOD 1000000007
int dy[4] = {-1,0,0,1};
int dx[4] = {0,1,-1,0};


int main(){

  int n;
  cin >> n;
  bool is = false;
  rep(i,25){
    if(i*4 > n)break;
    if((n-i*4)%7 == 0)is = true;
  }
  is ? cout << "Yes" << endl : cout << "No" << endl;





  

  return 0;
}