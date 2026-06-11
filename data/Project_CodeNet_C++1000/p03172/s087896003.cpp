//om nama sivaya
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define INF 9223372036854777ll
#define pb push_back
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    vector<ll> dp(k+1);
    dp[0]=1;
    for(int i=0;i<n;i++){//For each child
    vector<ll> fa(k+1);
        for(int j=k;j>=0;j--){//Used chocolates
        ll tmp=dp[j];
        int l=j+1;
        int r=j+min(a[i],k-j);
        if(l<=r){
            fa[l]+=tmp;
            if(fa[l]>=mod)
            fa[l]-=mod;
            if(r+1<=k)
            {fa[r+1]-=tmp;if(fa[r+1]<0)fa[r+1]+=mod;}
        }
        }
        ll pre=0;
    for(int i=0;i<=k;i++){
        pre+=fa[i];
        if(pre>=mod)
        pre-=mod;
        dp[i]+=pre;
        if(dp[i]>=mod)
        dp[i]-=mod;
    }
    }
    cout<<dp[k];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tt=1;
    //cin>>tt;
    while(tt--){
        solve();
    }
}
