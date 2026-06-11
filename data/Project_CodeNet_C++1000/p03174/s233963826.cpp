#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) ;
#define MOD 1000000007
#define int long long 
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define ff first
#define ss second
#define INF (1LL<<61)

using namespace std;


int n ;
int com[23][23];
int dp[23][(1<<22)];


int solve(int i , int womSet){
    if(i==n+1){
        if(womSet ==0)return 1;
        return 0;
    }

    if(dp[i][womSet] != -1) return dp[i][womSet];

    int ans =0;

    for(int wom =0 ; wom < n ; wom++ ){
        
        int ava = ((womSet&(1<<wom))==0 )? 0 : 1 ;

        if(ava && com[i][wom+1]){
           ans = (ans + solve(i+1 , womSet^(1<<wom)) )%MOD;
        }
    }

    return dp[i][womSet] =  ans ;
}

int32_t main(){   

fastio
// #ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("output.txt","w", stdout);
// #endif


memset(dp , -1 , sizeof(dp));
cin>>n;
for(int i =1; i<=n ; i++){
    for(int j =1 ; j<=n ; j++)cin>>com[i][j];
}


cout<<solve(1 , ((1<<n) -1));


return 0;
}

