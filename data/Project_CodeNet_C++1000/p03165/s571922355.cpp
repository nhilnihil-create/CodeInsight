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
const ll INF = INT_MAX;
const int mxm = 3005;

string s,t;
int dp[mxm][mxm];

void solve(){
    cin>>s>>t;
    memset(dp,0,sizeof(dp));
    //dp[0][0]=1;
    int n=s.length();
    int m=t.length();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    int len=dp[n][m];
    string str="";
    int i=n,j=m;
    while(i&&j){
        if(s[i-1]==t[j-1]){
            str=s[i-1]+str;
            i--;
            j--;
        }else if(dp[i-1][j]>dp[i][j-1])
                i--;
            else j--;
    }
    cout<<str;
}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}