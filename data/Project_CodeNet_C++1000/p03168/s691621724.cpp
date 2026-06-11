#include<bits/stdc++.h>

#define ll  long long int
#define ld  long double
#define MAX 1000001
#define MOD 1000000007
#define pi  3.14159265358979323846264338
#define mp  make_pair
#define pb  push_back
#define pll pair<ll,ll>
#define vl  vector<ll>
#define vi  vector<int>
#define vs  vector<string>
#define vc  vector<char>
#define fst first
#define sec second
#define foi(i, a, b)   for(ll i = a; i<b;i++)
#define fod(i, a, b)   for(ll i = a;i>=b;i--)
#define all(v)         (v).begin(), (v).end()
#define max3(a, b, c)  max(max(a,b), c)
#define min3(a, b, c)  min(min(a,b), c)
#define ump  unordered_map<ll,ll>
#define us   unordered_set<ll>
#define nl  "\n"
#define INF  (ll)1e18
#define s(v) (ll)(v).size()
#define e(v) (v).empty

using namespace std;

ll gcd(ll a,ll b) { if (a==0) return b; return gcd(b%a,a);}


void solve(){
    int n;
    cin>>n;

    vector<ld> p(n);
    foi(i,0,n) cin>>p[i];

    ld dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for(int i=1;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            if(j==0){
                dp[i][j] = dp[i-1][j]*(1 - p[i-1]);
            }else{
                dp[i][j] = dp[i-1][j]*(1-p[i-1]) + dp[i-1][j-1]*(p[i-1]);
            }
        }
    }
    ld ans = 0.0;
    foi(i,(n/2)+1,n+1){
        ans += dp[n][i];
    }
    cout<<setprecision(10)<<ans<<"\n";
}

int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("../input.txt", "r", stdin);
    //     freopen("../output.txt", "w", stdout);
    // #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    t = 1;
    //cin>>t;
    while(t--){
        solve();
    }

    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}