#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define sws ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define teto(a, b) ((a+b-1)/(b))
using namespace std;

const int MAX = 200010;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LLINF = 1000000000000000000;
const ld EPS = 1e-7;

// Extra
#define forn(i, n) for(int i = 0; i < (int)n; i++)
#define forne(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
//

ll sum(vl& v, int l, int r) {
    r = min(r, (int)v.size()-1);
    l = max(l, 0);

    ll val = v[r];
    if(l-1 >= 0)
        val = (val - v[l-1] + MOD) % MOD;

    return val;
}

int main() {
    sws;
    int n, k;
    cin >> n >> k;

    vector<vl> tab(n, vl(k+2, 0));

    vi a(n);
    forn(i, n)
        cin >> a[i];

    for(int j = 0; j <= a[0]; j++) {
        tab[0][j] = 1;
    }

    for(int i = 1; i < n; i++) {

        // prefix sum de tab[i-1]
        vl psum(k+1, 0);
        ll val = 0;
        for(int j = 0; j <= k; j++) {
            val = (val + tab[i-1][j]) % MOD;
            psum[j] = val;
        }

        for(int j = 0; j <= k; j++) {
            tab[i][j] = sum(psum, j-a[i], j);
        }
    }

    // forne(i, 0, n-1) {
    //     forne(j, 0, k) {
    //         cout << tab[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << tab[n-1][k] << endl;

    return 0;
}
