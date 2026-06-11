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

  ll n;
  cin >> n;
  bool is = true;
  if(n < 0)is = false,n *= -1;
  vector<bool> v(36,0);
  rep(i,36){
    if(is){
      if(!(i & 1))continue;
      if(n >> i & 1)n += (1 << i),v[i] = true;
    }else{
      if(i & 1)continue;
      if(n >> i & 1)n += (1 << i),v[i] = true;
    }
  }
  vector<int> res;
  rep(i,36){
    if((n >>i & 1) || v[i])res.push_back(1);
    else res.push_back(0);
  }
  reverse(ALL(res));
  if(n == 0){
    cout << 0 << endl;
  }else{
    int fir = 0;
    rep(i,36){
      if(res[i] == 1){
        fir = i;
        break;
      }
    }
    for(int i = fir;i < res.size();i++)cout << res[i];
    cout << endl;
  }





  

  return 0;
}