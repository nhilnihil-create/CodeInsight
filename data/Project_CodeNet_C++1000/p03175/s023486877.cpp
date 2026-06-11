#include <bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
template <class T1, class T2>void print(T1 a[], T2 n) { for (T2 i = 0; i < n; i++) { cout << a[i] << " ";} cout << endl;}
template <class T1, class T2>void print(vector<T1> a, T2 n) { for (T2 i = 0; i < n; i++) { cout << a[i] << " "; } cout << endl;}
ll modexpo(ll a, ll b, ll m) {if (b == 0) {return 1;} else if (a == 1) {return 1;} if (b % 2 == 0) {ll t = modexpo(a, b / 2, m); t = (t * t) % m; return t;} else {ll t = modexpo(a, b / 2, m); t = (t * t) % m; t = (t * a) % m; return t;}}

ll dp1[100004];
ll dp2[100004];
ll m = 1e9 + 7;

void dfs(ll x, vector<ll> g[], ll p) {

    for (int i = 0; i < g[x].size(); i++) {
        int t = g[x][i];
        if (t != p) {
            dfs(t, g, x);
            dp1[x] = (((dp1[t] + dp2[t]) % m) * dp1[x]) % m;
            dp2[x] = (dp1[t] * dp2[x]) % m;
        }
    }

}

int main() {

    // taskkill /IM "cp.exe" /F
    fast
//#ifndef ONLINE_JUDGE
  //  freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
//#endif


    ll n;
    cin >> n;
    vector<ll> g[n + 1];

    for (int i = 0; i < n - 1; i++) {
        ll x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }


    for (int i = 0; i <= n; i++) {
        dp1[i] = 1;
        dp2[i] = 1;
    }
    // cout << (dp1[1] + dp2[1] ) << endl;
    dfs(1, g, 0);
    cout << ((dp1[1] + dp2[1]) % m) << endl;





}