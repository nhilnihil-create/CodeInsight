#include<bits/stdc++.h>
#define int         int64_t
#define pb          push_back
#define endl        '\n'
#define pll         pair<int,int>
#define vll          vector<int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mi        map<int,int>
#define gcd(a,b)    __gcd((a),(b))
#define lcm(a,b)    ((a)*(b)) / gcd((a),(b))
#define ios     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 
int n,i,j,k,l,sum=0,flag=0,t,a[200005],ans=0;
bitset<4000001> dp;
void solve(){
    dp[0]=1;
    cin>>n;
    int sum = 0;
    for(int i=0;i<n;i++){
        cin>>j;
        sum+=j;
        dp|=(dp<<j);
    }
    for(int i=0;i<=sum;i++){
        if(dp[i]&& i>=(sum+1)/2) {
            cout<<i<<endl;
            return;
        }
    }
}
signed main()
{
    ios
    int test=1;
    //cin>>test;
    while(test--){
        solve();
    }
    return 0;
}