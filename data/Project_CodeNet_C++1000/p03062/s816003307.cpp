#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define endl '\n'

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const ll mod=1000000007;
//head

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vll a(n);
    rep(i,0,n) cin >> a[i];
    
    vector<vector<ll>> dp(n+1,vll(2,-(1LL << 30)));
    dp[0][0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2; j++) {
            if(j == 0)
                dp[i+1][0] = max(dp[i][0] + a[i], dp[i][1] - a[i]);
            else dp[i+1][1] = max(dp[i][0] - a[i], dp[i][1] + a[i]);
        }
    }
    cout << dp[n][0] << endl;
    return 0;
}
