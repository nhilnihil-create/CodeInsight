#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define sz size
#define se second
#define fe first
#define mper make_pair
#define all(x) x.begin(), x.end()
#define mal ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
#define vl vector<ll>
#define vi vector<int>
#define vli vector <pair <ll, int> >
#define vll vector <pair <ll, ll> >
#define vii vector <pair <int, int> >
using namespace std;

const ll MOD = 1e9 + 7;
const ll MAXN = 2e5 + 100;
ll n, a[MAXN], pos[MAXN], dp[MAXN];

void compress() {

    vector <ll> g;

    for(int i = 1; i <= n; ++i) {

        if(a[i] != a[i - 1]) {g.pb(a[i]);}

    }

    n = g.sz();

    for(int i = 1; i <= n; ++i) {

        a[i] = g[i - 1];
        pos[a[i]] = i;
    }

}

void solve() {


    cin >> n;

    for(int i = 1; i <= n; ++i) {

        cin >> a[i];

    }

    compress();

    dp[0] = 1;

    for(int i = 1; i <= n; ++i) {

        dp[i] = (dp[i] + dp[pos[a[i]]] + dp[i - 1]) % MOD;
        pos[a[i]] = i;
    }

    cout << dp[n];

}

int main(){

mal
//freopen("ladder.in", "r", stdin);
//freopen("ladder.out", "w", stdout);

ll tt = 1;


while(tt--) {

    solve();

}

return 0;
}

