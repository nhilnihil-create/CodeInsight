#include<bits/stdc++.h>
#define ll long long 
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define UB upper_bound
#define LB lower_bound
#define BS binary_search
#define PI 3.1415926535897932384626433832795
#define F first
#define S second
#define V vector<ll>
#define ALL(sss) sss.begin(),sss.end()
#define arall(rr,n) rr+0,rr+n 
#define mod 1000000007
#define M 100
#define MAXN 1000000000

 
int dp[262145][2];
int ans=INT_MAX;
ll n;
using namespace std;


void fileio(){
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
}




int main(){


     fileio();
    
   
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  

    ll T=1,q;
    //cin>>T;
    while(T--){

        ll n,k;cin>>n>>k;
        ll a[n];
        for (int i = 0; i < n; ++i)
        {
            /* code */cin>>a[i];
        }

        vector<ll> dp(n+1,INT_MAX);

        dp[0]=0;dp[1]=abs(a[1]-a[0]);
        for (ll i = 2; i <= n; ++i)
        {
            for(ll j=1;j<=min(k,i);j++){//cout<<i<<" "<<j<<endl;
                dp[i]=min(dp[i-j]+abs(a[i-j]-a[i]),dp[i]);
            }//cout<<endl;
        }

        cout<<dp[n-1];

        // cout<<"Case #"<<q<<": "<<ans<<endl;
    }
    
//prllf("%.9f\n", x);//precision: 9 decimal places.

/*
    GP SUM:(
    (bk)-a)/k-1;//k is ratio and b is final term, a is initial term;

    Comparing two decimal numbers

    if (abs(a-b) < 1e-9) {
        // a and b are equal
    }
*/
    return 0;
}
