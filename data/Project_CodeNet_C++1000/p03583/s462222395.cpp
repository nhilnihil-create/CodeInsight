#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int main(){

  ll N;
  cin >> N;
  for(int i = 1;i <= 3500;i++){
    for(int j = 1;j <= 3500;j++){
      ll k = N*i*j;
      ll l = 4*i*j-N*i-N*j;
      if(l <= 0)continue;
      if(k%l == 0){
        printf("%d %d %d\n",i,j,k/l);
        return 0;
      }
    }
  }

  
  




  return 0;
}