#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define ull unsigned long long
#define ff first
#define ss second
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define test int t;cin>>t;while(t--)
#define mp make_pair
#define modInv(n) po(n,mod-2)%mod
#define ncr(n,r) (((fact[n]*modInv(fact[r]))%mod)*modInv(fact[n-r]))%mod
#define setbits(y) __builtin_popcountll(y)
#define mod 1000000007

ll po(int a,int b){
    if(b==0) return 1;
    ll ans=1;
    if(b%2==0){
        ans = po(a,b/2)%mod;
        ans=(ans%mod * ans%mod)%mod;
    }
    else{
        ans = po(a,(b-1)/2)%mod;
        ans = (ans%mod * ans%mod * a)%mod;
    }
    return ans%mod;
}


void solve(){
   ll n,k,i,j;
   cin>>n>>k;
   ll arr[n+1];
   for(i=1;i<=n;i++) cin>>arr[i];
   ll dp[n+1]={};
   for(i=2;i<=n;i++){
       ll val = 1000000007;
       for(j=1;j<=k;j++){
           if(i-j>=1){
                val = min(val , dp[i-j]+abs(arr[i]-arr[i-j]));
           }
       }
    //   cout<<val<<" ";
      dp[i]=val;
   }
  cout<<dp[n];
}


int main(){
    IOS
    // test{
    //     solve(); cout<<"\n";
    // }
    solve();
}