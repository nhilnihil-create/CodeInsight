    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long int
    #define f(i,n) for(ll i=0;i<n;i++)
    #define rf(i,n) for(ll i=n-1;i>=0;i--)
    #define f2(i,n) for(ll i=1;i<=n;i++)
    #define endl "\n"
    #define vll vector <ll>
    #define sz(a) (ll)a.size()
    #define all(a) (a).begin(),(a).end()
    #define mod 1000000007
    #define pb push_back
    const ll inf =1e13+5;

    typedef pair<ll,ll> pll;

    ll gcd(ll a, ll b){if(b==0)return a;return gcd(b, a%b);}
    ll lcm(ll a, ll b){return a*b/gcd(a, b);}
    ll fexp(ll a, ll b){ll ans = 1;while(b){if(b&1) ans = ans*a%mod; b/=2;a=a*a%mod;}return ans;}
    ll inverse(ll a, ll p){return fexp(a, p-2);}

    void solve(){
        ll n;cin>>n;
        ll k;cin>>k;
        vll a(n+1);
        for(int i=1;i<=n;i++)cin>>a[i];

        vector<vector<ll>>dp(n+1,vector<ll>(k+1,0));
        vector<ll>sum(k+1,0);
        dp[0][0]=1;
        for(int j=1;j<=k;j++)dp[0][j]=0;
        for(int i=1;i<=n;i++)dp[i][0]=1;

        for(int i=1;i<=n;i++){
            sum[0]=dp[i-1][0];
            for(int j=1;j<=k;j++){
                sum[j]=dp[i-1][j]+sum[j-1];
            }
            // f(temp,k+1)cout<<sum[temp]<<" ";
            for(int j=1;j<=k;j++){
                ll left=max((ll)0,j-a[i]);
                ll right=j;
                dp[i][j]=sum[right]-sum[left]+dp[i-1][left];
                dp[i][j]%=mod;
            }
        }
        cout<<dp[n][k]<<endl;

    }
    
    

    int main(){
        ios_base::sync_with_stdio(0) ;
        cin.tie(0) ; cout.tie(0) ;

        ll t;
        t=1;
        // cin>>t;
        while(t--){
           solve();
        }
       

        // #ifndef ONLINE_JUDGE
        // cout<<"\nTime Elapsed: "<<1.0*clock()/ CLOCKS_PER_SEC<<" Sec\n";
        // #endif

        
        return 0;
    }