//#pragma GCC optimize ('O3')
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define f first
#define s second
#define pb push_back

const int N = 50 + 5;
const int M = 100 + 5;
const ll OO = 1e18;
const int mod = 1e9 + 7;

int n,k,v[N],dp[N][N][M];

int solve(int s, int e, int g) {

    if(s>e) return 0;

    int &ret = dp[s][e][g];

    if(~ret) return ret;
    
    ret = 0;

    if(g>=1) {

        ret = max({ret, solve(s,e-1,g-1)+v[e],solve(s+1,e,g-1)+v[s]});

    }

    if(g>1) {

        ret = max({ret, solve(s,e-1,g-2),solve(s+1,e,g-2)});

    }

    return ret;

}

void init() {

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    memset(dp, -1, sizeof dp);

    cout << solve(0, n-1, k) << '\n';

    return 0;
}