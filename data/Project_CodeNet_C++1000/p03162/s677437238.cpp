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

        ll n,k;cin>>n;
        ll a[n],b[n],c[n];
        for (int i = 0; i < n; ++i)
        {
            /* code */cin>>a[i]>>b[i]>>c[i];
        }

        ll dp[n+1][3];

        dp[0][0]=a[0];
        dp[0][1]=b[0];
        dp[0][2]=c[0];

        
        for (ll i = 1; i < n; ++i)
        {
            dp[i][0]=a[i]+max(dp[i-1][1],dp[i-1][2]);
            dp[i][1]=b[i]+max(dp[i-1][0],dp[i-1][2]);
            dp[i][2]=c[i]+max(dp[i-1][0],dp[i-1][1]);
        }

        cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});

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
