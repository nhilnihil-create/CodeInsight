#include <bits/stdc++.h>
using namespace std;
#define fix(f,n) std::fixed<<std::setprecision(n)<<f
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;
typedef unsigned long long int ull;
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a>b)?b:a)
#define max3(a,b,c) ((a>b)?(a>c)?a:c:(b>c)?b:c)
#define min3(a,b,c) ((a<b)?(a<c)?a:c:(b<c)?b:c)
#define REP(i,a,n) for(ll i=a;i<n;i++)
#define pb push_back
#define mp make_pair

int n;
bool c[21][21]={};
ll dp[1<<21];

ll dfs(int ind,int mask){
    if(ind==n){
        return 1;
    }
    if(dp[mask]!=-1){
        return dp[mask]%1000000007;
    }
    ll ans=0;
    for(int i=0 ; i<n ; i++){
        if(c[ind][i] && ((1<<i)&mask)==0){
            ans+=dfs(ind+1,mask|(1<<i));
            ans%=1000000007;
        }
    }
    return dp[mask]=ans%1000000007;
}

int main(){
	fast;
	int test=1;
	//cin >> test;
	while(test--){
	    cin >> n;
	    memset(dp,-1,sizeof dp);
	    for(int i=0 ; i<n ; i++){
	        for(int j=0 ; j<n ; j++){
	            cin >> c[i][j];
	        }
	    }
	    dfs(0,0);
	    cout << dp[0] << endl;
	}
	return 0;
}