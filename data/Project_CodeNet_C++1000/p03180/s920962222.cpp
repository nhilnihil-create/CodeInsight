#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define mp make_pair
#define endl "\n"
#define pii pair<int,int> 
#define ff first
#define ss second
#define mii map<int,int>
#define si set<int>
#define sti stack<int>
#define qi queue<int>
#define vi vector<int>
#define pq priority_queue<int>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int M=1e9+7;
const int N=(1<<16)+200,N1=20;
int n,a[N1][N1];
int dp[N];

int merge(int x){
    vi v1;
    for(int i=0;i<16;i++){
        if(x & (1<<i)){v1.pb(i);}
    }
    int ans=0;
    for(int i=0;i<v1.size();i++){
        for(int j=i+1;j<v1.size();j++){
            ans+=a[v1[i]][v1[j]];
        }
    }
    return(ans);
}

int find(int mask){
    if(dp[mask]!=-1e18) return(dp[mask]);
    dp[mask]=merge(mask);
    for(int s=mask;s>0;s=(s-1)&mask){    
        if(s==mask) continue;
        dp[mask]=max(dp[mask],find(s)+find(mask^s));
    }
    return(dp[mask]);
}

int32_t main(){
    IOS;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<N;i++) dp[i]=-1e18;
    int x=(1<<n)-1;
    cout<<find((1<<n)-1);
}