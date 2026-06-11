#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define re reverse
#define ps push
#define in insert
#define sv(v) shuffle(all(v), default_random_engine())
#define sa(a, n) shuffle(a, a+n, default_random_engine())
#define ca(v) for(auto i:v) cout<<i<<" ";
#define nl cout<<"\n"
#define del(s, x) s.erase(s.find(x))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a*b/gcd(a, b))
#define debug cout<<"DEBUG\n"
const int MOD = 1e9 + 7;
const int MAXN = 3e3+5;

double dp[MAXN][MAXN];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    double ar[n];
    for(int i=0; i<n; i++) cin>>ar[i];
    dp[0][0] = 1-ar[0];
    dp[0][1] = ar[0];
    for(int i=1; i<n; i++){
        for(int j=n; j>0; j--) {
            dp[i][j]+=dp[i-1][j-1] * ar[i];
            dp[i][j]+=dp[i-1][j] * (1-ar[i]);
        }
        dp[i][0] = dp[i-1][0] * (1-ar[i]);
    }
    double tot = 0;
    for(int i=n/2+1; i<=n; i++){
        tot+=dp[n-1][i];
    }
    cout<<fixed<<setprecision(12)<<tot;
}

