#include "bits/stdc++.h"
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int,int>
#define mii map<int,int>
#define all(c)  c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b)  (x/gcd(x,y))*y
#define inf (long long) 1e18
#define neg_inf (long long) (-1*1e18)
#define F first
#define S second
#define sz(x) ((int)(x).size())
#define rep(i,n)  for(int i=0;i<n;i++)
#define repd(i,n) for(int i=n-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define deb(x) cout << #x << "=" << x <<"\n";
const int N = 1e9 + 7;

int pow(int x, int y) { int res = 1; while (y > 0) { if (y & 1) res = ((res) * (x)); res %= N; y = y >> 1; x = ((x) * (x)); } return res; }
int pow(int x, int y, int p)  {  int res = 1; x = x % p; while (y > 0) {if (y & 1) res = (res * x) % p; y = y >> 1; x = (x * x) % p;}   return res; }


vector<vector<double>> dp(3000,vector<double> (3000,0));
void solve()
{
    int n;
    cin>>n;
    vector<double> v(n+1);
    rep1(i,n)
        cin>>v[i];

    // for(int i=1;i<=n;i++)
    //     cout<<v[i]<<" ";
    // cout<<"\n";

    // for(int i=1;i<=n;i++)
    // {
    //     dp[i][0]=1;
    // }
    dp[0][0]=1;

    int proper=(n+1)/2;

    for(int i=1;i<=n;i++)
    {
        dp[i][0]=(1-v[i])*dp[i-1][0];
        for(int j=n;j>=1;j--)
        {
            // cout<<v[i]<<"\n";
            // cout<<dp[i][j-1]*(v[i])<<" ";
            // return;
            dp[i][j]=dp[i-1][j-1]*(v[i])+dp[i-1][j]*(1-v[i]);
            // cout<<i<<" "<<j<<" ";
            // cout<<dp[i][j]<<"\n";
        }
        // cout<<"\n";
    }

    // printf("%.3f ",dp[1][1]);

    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //     {
    //         cout<<fixed<<setprecision(3)<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // cout<<"\n";


    double ans=0;
    for(int i=proper;i<=n;i++)
    {
        ans+=dp[n][i];
    }
    printf("%0.10f",ans);
} 



int32_t main()
{
  // #ifndef ONLINE_JUDGE
 //    freopen("gymnastics.in", "r", stdin);
 //    freopen("gymnastics.out", "w", stdout);
  // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    // cin>>t;

   while(t--)
   {
      solve();
   }
}






//code by-Roshan











//unnecessary
// bool cmp(pair<int,int> &a,pair<int,int> &b)
// {
//  if(a.F==b.F)
//    return (a.S<b.S);
//  else 
//    return (a.F<b.F);
//  //< =chota wala pehle
//  //> =chota wala baad me
// }


//better use this structure
// struct s{
//  int a;
//  bool operator <(const s &x) const
//  {
//    return (a>x.a);
//  }
// };



//  priority_queue<int,vector<int>,greater<>> p;(priority queue as min heap)


//important to use this one
// cout<<fixed<<setprecision(3)<<dp[i][j]<<" ";

