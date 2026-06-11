#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cerr << '\n'; }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << " "; err(++it, args...); }

#define        optimize           ios::sync_with_stdio(0); cin.tie(0);
#define PI    acos(-1.0)
#define pb push_back
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define RESET(a, b) memset(a, b, sizeof(a))
#define pii pair <int, int>
#define gcd(a, b) __gcd(a, b)
#define min3(a, b, c) min(c, min(a, b))
#define max3(a, b, c) max(c, max(a, b))

const ll MX = 4e2 + 5;
const ll inf = 1e18 + 5;

ll dp[MX][MX];
ll ara[MX];
ll sum[MX];

void solve(int l, int r)
{
    if(l == r){
        dp[l][r] = 0;
        return;
    }
    if(dp[l][r] != -1) return;

    ll &res = dp[l][r];
    res = inf;
    for(int i = l; i <= r; i++){
        solve(l, i);
        solve(i+1, r);
        dp[l][r] = min(dp[l][r], dp[l][i]+dp[i+1][r]+(sum[r]-sum[l-1]));
    }
}


int main()
{
    optimize
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>ara[i];
        sum[i] = sum[i-1]+ara[i];
    }
    RESET(dp, -1);
    solve(1, n);
    cout<<dp[1][n]<<endl;
}
