#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll M=1000000007LL;

ll modpow(ll x, ll y){
  if(y==0) return 1;
  if(y==1) return x%M;
  if(y%2==0) return modpow(x*x%M, y/2)%M;
  return modpow(x*x%M, y/2)%M*x%M;
}

ll modinv(ll x){
  return modpow(x, M-2);
}

ll invsum[100001];
int main(){
  invsum[0]=0;
  ll N, A[100001];
  cin >> N;
  for(int i=1;i<=N;i++){
    cin >> A[i];
    invsum[i]=(invsum[i-1]+
               modinv(i))%M;
  }
  
  ll ans=0;
  for(int i=1;i<=N;i++){
    ans=(ans+(invsum[i]+
      invsum[N+1-i]-1)%M
      *A[i]%M)%M;
  }
  for(int i=1;i<=N;i++)
    ans=ans*i%M;
  
  cout << ans << endl;
  
  return 0;
}