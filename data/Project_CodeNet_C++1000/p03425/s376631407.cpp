#include <bits/stdc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;

#define ll  unsigned long long
#define PR  pair<int, int>

const int N = 3e5 + 10;
const int MOD = 1e9 + 7;
const long long INF = 5e18;
const double PI = 2 * acos(0.0);
//template<typename T> using ordered_set = tree<T, nulong long_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

string key = "MARCH";
map<char, ll> mob;
ll ans;

void fun(int pos, int cnt, ll now) {
    if (cnt == 3) {
        ans += now;
        return;
    }
    if (pos == key.size()) {
        if (cnt == 3) ans += now;
        return;
    }
    fun(pos + 1, cnt, now);
    fun(pos + 1, cnt + 1, now * mob[key[pos]]);
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mob[s[0]]++;
    }
    fun(0, 0, 1);
    cout << ans << '\n';
    return 0;
}
