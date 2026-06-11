#include<bits/stdc++.h>
typedef long long int LL;
typedef unsigned long long int ULL; 
typedef long double dd; 
#define endl "\n"
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
LL dp[2000001];
LL mod=1e9+7;
bool vis[100000],ok=1;
using namespace std;
bool isPrime(LL n) {
  LL j; 
  for( j=2;j<=sqrt(n);j++){
    if(n%j==0){
      break;  
    } 
  }
  if(j>sqrt(n)){
    return 1; 
  }
  else{
    return 0; }
}
LL modexpo(LL a, LL b) {
  LL ans=1;
  a=a%mod;
  while(b>0){
    if((b&1)==1){
      ans=((ans%mod)*(a%mod))%mod;
    }
    b=b>>1;
    a=((a%mod)*(a%mod))%mod;
  }
  return ans; 
}
LL invmod(LL n){
  return modexpo(n,mod-2);
}
LL comb(LL n,LL r){
  if(r==0){
    return 1;
  }
  LL fact[n+1];
  fact[0] = 1; 
    for (LL i = 1; i <= n; i++){
       fact[i] = (fact[i - 1] * i) %mod;}
    return (fact[n] * invmod(fact[r]) % mod * invmod(fact[n - r]) % mod) %mod; 
}
LL gcd(LL a, LL b) {
  if (a == 0){
       return b;
       }  
    return gcd(b % a, a);  
}
LL lcm(LL a, LL b) {
  return (a*b)/gcd(a,b);
}
void solve(LL k){
  LL n,f;
  cin>>n>>f; 
  LL a[n];
  for(LL i=0;i<n;i++){
    cin>>a[i];
  }
  LL d[n];
  for(LL i=0;i<n;i++){
    d[i]=INT_MAX;
  }
  d[0]=0,d[1]=abs(a[1]-a[0]);
  for(LL i=2;i<n;i++){
    LL g=i+1;
    for(g=1;g<=f;g++){
      if(i-g>=0){
    d[i]=min(d[i],d[i-g]+abs(a[i]-a[i-g]));
  }
  }
  }
  cout<<d[n-1]<<endl; 
}
int main(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
 LL t=1;
//cin>>t;
 LL k=1;
while(k<=t){
  if(ok==0){
    break; 
  }
   solve(k);
  k++;
  }
   return 0;
   }