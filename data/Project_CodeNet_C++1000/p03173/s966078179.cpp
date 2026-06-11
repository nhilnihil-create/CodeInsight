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
const ll inf = 1e18L + 5;

ll ara[MX];
ll dp[MX][MX];

ll sum(int l, int r)
{
    ll ans = 0;
    for(int i = l; i <= r; i++) ans += ara[i];
    return ans;
}

int main()
{
    optimize
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) cin>>ara[i];

    RESET(dp, inf);

    for(int R = 0; R < n; R++){
        for(int L = R; L >= 0; L--){
            if(L == R) dp[L][R] = 0;
            else{
                ll s = sum(L, R);
                for(int i = L; i <= R; i++){
                    dp[L][R] = min(dp[L][R], dp[L][i]+dp[i+1][R]+s);
                }
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
}
