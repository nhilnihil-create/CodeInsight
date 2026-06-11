#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (ll i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 305
string s; int n; int k;
int dp[MN][MN][MN];
int calc(int l, int r, int x){
    if(dp[l][r][x] != -1) return dp[l][r][x];
    if(r < l){
        dp[l][r][x] = 0;
        return 0;
    }
    if(l == r){
        dp[l][r][x] = 1;
        return 1;
    }
    int mx = 0;
    mx = max(mx, calc(l, r-1, x));
    mx = max(mx, calc(l+1, r, x));
    if(s[l] == s[r]){
        mx = max(mx, calc(l+1, r-1, x)+2);
    } else if(x != 0){
        mx = max(mx, calc(l+1, r-1, x-1)+2);
    }
    dp[l][r][x] = mx;
    return mx;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s >> k; n=s.length();
    memset(dp, -1, sizeof dp);
    cout << calc(0, n-1, k) << "\n";
    
    return 0;
}
