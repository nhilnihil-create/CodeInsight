#include <bits/stdc++.h>

#define deb(x) cout << #x << "=" << x << endl;
#define fo(i, n) for (ll i = 0; i < n; i++)
#define fo1(i, n) for (ll i = 1; i <= n; i++)i
#define sn(x) cin >> x;
#define pn(x) cout << x << "\n"
#define ps(x) cout << x << " ";
#define pb() cout << "\n";
#define sort(x) sort(x.begin(), x.end())

using namespace std;


typedef long long ll;
ll INF = INT_MAX;



void solve()
{

    ll n;
    cin >> n;
    vector<ll>v(n),dp(n);

fo(i,n){
    cin>>v[i];
    dp[i]=INF;
}
   
dp[0]=0;
dp[1]=abs(v[1]-v[0]);

for(ll i=2;i<n;i++){
    for(ll j=1;j<=2;j++){
           dp[i]= min(dp[i],abs(v[i-j]-v[i])+dp[i-j]);
       } 
   }

    cout << dp[n-1] << endl;

}

int main()
{

#ifndef ONLINE_JUDGE
   freopen("a.in", "r", stdin);
    freopen("err.txt", "w", stderr);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll test = 1;
    //cin >> test;
    while (test--)
    {
        ll n;

        solve();
    }
}
