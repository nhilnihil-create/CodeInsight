#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb push_back
#define ss second
#define ff first 
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
const ll M=1000000007;
ll power(ll x,ll n){if(n==0)return 1;else if(n%2==0)return (power((x*x)%M,n/2))%M;else return ((x%M)*power(x,n-1)%M);}
ll ncr(int n,int r){if(r>n)return 0;if(r > n - r) r = n - r;ll ans = 1;
int i;for(i = 1; i <= r; i++){ans *= n - r + i;ans /= i;}return ans;}
ll nCrModpDP(ll n, ll r, ll p){ 
    ll C[r+1]; 
    memset(C, 0, sizeof(C)); 
    C[0] = 1;
    for (ll i = 1; i <= n; i++){ 
        for (ll j = min(i, r); j > 0; j--) 
            C[j] = (C[j] + C[j-1])%p; 
    } 
    return C[r]; 
} 
ll ncrmod(ll n, ll r, ll p){ 
   if (r==0) 
      return 1; 
   ll ni = n%p, ri = r%p; 
   return (ncrmod(n/p, r/p, p) * 
           nCrModpDP(ni, ri, p)) % p;  
} 
ll modInverse(ll a,ll m) 
{ 
   ll m0 = m; 
   ll y = 0, x = 1; 
  
    if (m == 1) 
      return 0; 
  
    while (a > 1) 
    { 
       ll q = a / m; 
       ll t = m; 
        m = a % m, a = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    } 
    if (x < 0) 
       x += m0; 
  
    return x; 
} 
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
string str;
cin>>str;
stack<char>sec;
sec.push(str[0]);
for(int i=1; i<str.length(); i++){
if(sec.empty()){
sec.push(str[i]);
}
else if(str[i]=='1'){
if(!sec.empty()){
if(sec.top()=='0')
sec.pop();
else
sec.push(str[i]);
}else{
sec.push(str[i]);
}
}
else if(str[i]=='0'){
if(!sec.empty()){
if(sec.top()=='1')
sec.pop();
else
sec.push(str[i]);
}else{
sec.push(str[i]);
}
}
}
int n=str.length();
// cout<<sec.size()<<"\n";
cout<<n-(sec.size());
return 0;
}