//Kriti Verma
#include<bits/stdc++.h>
#define     ll          long long
#define     MOD         1000000007
#define     pb          push_back
#define     vll         vector<long long>
#define     vi          vector<int>
#define     vl          vector<long>
#define     pii         pair<int, int>
#define     pll         pair<ll,ll>
#define     mp          make_pair
#define     all(a)      (a).begin(),(a).end()
#define     rep(i,a,b)  for(int i=a;i<b;i++)
#define     lcm(a,b)    (a*b)/__gcd(a,b)
#define     MAX         100002 
#define     ios          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

ll n;
ll dp[MAX];
vll a(MAX);

int minCost(ll idx){
    if(idx>=n)return INT_MAX;
    if(idx==n-1)return 0;
    if(dp[idx]!=-1)return dp[idx];
    dp[idx]=min(minCost(idx+1)+abs(a[idx]-a[idx+1]),minCost(idx+2)+abs(a[idx]-a[idx+2]));
    return dp[idx];
}
int main(){
    
    ios
    memset(dp,-1,sizeof dp);
    cin >> n;
    for(ll i=0;i<n;i++)cin >> a[i];
    cout << minCost(0) <<  "\n";    
    return 0;
}

