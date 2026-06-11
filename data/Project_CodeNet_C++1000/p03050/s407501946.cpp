#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>

using namespace std;

#define int long long
#define ll long long
#define ld long double
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<vi>
#define viii vector<vii>
#define vpii vector<pii>
#define vb vector<bool>
#define vbb vector<vb>
#define vs vector<string>
#define pb push_back
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define in(a, start) for (int i = start; i < (a).size(); ++i) cin >> (a)[i]
#define out(a) for (auto qwe : a) cout << qwe << " "
#define tests int test; cin >> test; while (test--)
#define fileio() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)

const int INF = 1e9;
const int INF64 = 1e18;
const int MOD = 1e9 + 7;
const int MOD9 = 1e9 + 9;
const int MOD3 = 998244353;
const int P = 37;

const int mxn = 200000;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if (n == 1) {
        cout << 0;
        return 0;
    }

    int s = 0;

    for (int nm = 1; nm <= sqrt(n); ++nm) {
        int m = n / nm - 1;

        if (nm == n % m) s += m;
    }

    cout << s;
}

