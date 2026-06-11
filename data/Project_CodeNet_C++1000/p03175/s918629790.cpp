#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long

int bs_upper_bound(int a[], int n, int x) {
    int l = 0;
    int h = n; // Not n - 1
    while (l < h) {
        int mid =  l + (h - l) / 2;
        if (x >= a[mid]) {
            l = mid + 1;
        } else {
            h = mid;
        }
    }
    return l;
}

int bs_lower_bound(int a[], int n, int x) {
    int l = 0;
    int h = n; // Not n - 1
    while (l < h) {
        int mid =  l + (h - l) / 2;
        if (x <= a[mid]) {
            h = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

bool sortbysec(const pair<int,int> &a,const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 

int n;
vector<int> g[100001];
ll mod=1e9+7;
ll dp[100001][2];

ll dfs(int x,int f,int p){
    if(dp[x][f]!=0)
        return dp[x][f];
    dp[x][f]=1;
    for(int i=0;i<g[x].size();i++){
        if(g[x][i]!=p){
            if(f==0)
                dp[x][0]=(dp[x][0]*((dfs(g[x][i],1,x)+dfs(g[x][i],0,x))%mod))%mod;
            if(f==1)
                dp[x][1]=(dp[x][1]*dfs(g[x][i],0,x))%mod;
        }
    }
    return dp[x][f];
}

int main()
{
    IOS;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        dp[i][0]=0;
        dp[i][1]=0;
    }
    ll x=dfs(0,0,-1);
    ll y=dfs(0,1,-1);
    cout<<(x+y)%mod;
}
