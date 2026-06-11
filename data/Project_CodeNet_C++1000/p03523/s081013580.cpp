#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for (int i = a; i <= (b); i++)
#define ROF(i, a, b) for (int i = a; i >= (b); i--)

using pii = pair<int, int>; using vpii = vector<pii>;
using vi = vector<int>; using vvi = vector<vi>;
using ll = long long;
using pll = pair<ll, ll>; using vpll = vector<pll>;
using vll = vector<ll>; using vvll = vector<vll>;

int main() {
    map <string, bool> ok;
    
    function <void(string)> dfs = [&] (string a) {
        // cout << a << endl;
        ok[a] = 1;
        FOR(i, 0, sz(a) - 1) {
            if (a[i] == 'A') {
                string b = a;
                b.erase(b.begin() + i);
                dfs(b);
            }
        }
    };

    dfs("AKIHABARA");

    string s; cin >> s;
    if (ok[s]) cout << "YES\n";
    else cout  << "NO\n";
}