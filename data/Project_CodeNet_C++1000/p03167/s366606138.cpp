/*
Created by Rishu Sahu @ covid 20-20
*/
/*
*****************************************************************
*/

#include<bits/stdc++.h>
using namespace std;

#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define pai pair<int,int>
#define pal pair<ll,ll>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,a,b) for(int i=a;i<=b;i++)
#define ff first 
#define ss second
#define sz(x) (int)x.size()
#define vi vector<int>
#define vl vector<ll>
#define mpl map<ll,ll>
#define mpi map<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()

const int mod = 1e9+7;
const int INF = INT_MAX;

vi adj[100005];
int ind[100005];
int longest[100005];


void solve(){
    int n,m;
    cin>>n>>m;
    int mat[n][m];
    ll dp[n][m];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char ch;
            cin>>ch;
            if(ch=='.') mat[i][j]=1;
            else mat[i][j]=0;
        }
    }
    dp[0][0]=1;
    for(int i=1;i<m;i++){
        if(dp[0][i-1]&&mat[0][i]) dp[0][i]=1;
    }
    for(int i=1;i<n;i++){
        if(dp[i-1][0]&&mat[i][0]) dp[i][0]=1;
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(mat[i][j]) dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
        }
    }
    cout<<dp[n-1][m-1]%mod<<endl;

}

int main(){
    solve();
}
