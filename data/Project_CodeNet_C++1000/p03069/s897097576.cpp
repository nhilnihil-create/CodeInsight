#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
/*
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
*/
#define ull unsigned long long int
#define ll long long int
#define MAX 1000000007
//1e9+7
#define pll pair<ll,ll>
#define pii pair<int,int>
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FO ifstream fin("a.in");ofstream fout("a.out");
#define TEST ll T;cin>>T;while(T--)
#define all(x) (x).begin(),(x).end()
#define mset0(x) memset((x), 0, sizeof((x)));
#define mset1(x) memset((x), -1, sizeof((x)));
typedef tree<ll,null_type,less<ll>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

void solve(){
    int n,ans=200001;
    cin>>n;
    string s;
    cin>>s;
    int dp[n+1][2];
    memset(dp,0,sizeof dp);
    for(int i=1;i<=n;i++){
        dp[i][0]=dp[i-1][0];
        dp[i][1]=dp[i-1][1];
        if(s[i-1]=='.') dp[i][0]++;
        else dp[i][1]++;
    }
    for(int i=0;i<=n;i++){
        ans=min(ans,dp[i][1]+dp[n][0]-dp[i][0]);
    }

    cout<<ans;
    return;
}
int main(){
    IO
    //TEST
    solve();
    return(0);
}
