/* ****VIKRAM ADITYA**** */
#include<bits/stdc++.h>

#define ll          long long
#define F           first
#define S           second
#define pb          push_back
#define mp          make_pair
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define ld             long double
#define hell        1000000007
#define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    #endif
    ll t = 1;
    // cin>>t;
    while(t--)
    {
        cout<<setprecision(15);
        ll n;
        cin>>n;
        vector<double> v(n+1);
        v[0]=0.0;
        for (int i = 1; i <= n; ++i)
        {
            cin>>v[i];
        }

        // ll cnt?=0;
        double one=1.0;
        double dp[n+1][n+1]={0.0 };
        // ll cnt[n][2]={0 };

        dp[1][0]=one-v[1];
        // cnt[0][0]=0;
        dp[1][1]=v[1];
        // cnt[0][1]=1;

        for (int i = 2; i <= n; ++i)
        {
            dp[i][0]=dp[i-1][0]*(one-v[i]);
            for(int j=1;j<=i;j++)
            {
                dp[i][j]=(dp[i-1][j]*(one-v[i]))+(dp[i-1][j-1]*v[i]);
            }
        }

        double ans=0.0;
        for(int i=(n)/2+1;i<=n;i++)
            ans+=dp[n][i];

        cout<<ans;

        
    }

    
    time
    return 0;
}