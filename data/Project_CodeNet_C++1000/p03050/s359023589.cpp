#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 998244353
#define MAX 100
#define INF 800000000

int main(){
  ll N;
  cin>>N;
  ll ans=0;
  for(ll i=1;i<=sqrt(N);i++){
    if(N%i==0){
      ll m=N/i-1;
      if(m==0){
        continue;
      }
      if(N/m==N%m){
        ans+=m;
      }
    }
  }
  cout<<ans<<endl;
}
