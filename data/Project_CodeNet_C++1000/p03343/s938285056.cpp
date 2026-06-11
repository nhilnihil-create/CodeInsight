#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
#include <map>
#include <deque>

using namespace std;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef long double ld;

const ll SIZE = 1e6 + 10, S2 = 1e7 * 2, MOD = 1e9 + 7, INF = 1e9 * 1e9 + 100;

vector<ll> pr, xr;
vector<ll> vec, srt;
vector<ll> nw;
vector<pair<ll, ll>> ps;

ll n, k, q, tree[SIZE * 4];

void build(int v, int l, int r) {
    if (l == r - 1) {
        tree[v] = vec[l];
    }
    else {
        int m = (l + r) / 2;
        build(v * 2 + 1, l, m);
        build(v * 2 + 2, m, r);
        tree[v] = min(tree[v * 2 + 1], tree[v * 2 + 2]);
    }
}

ll get(int v, int l, int r, int askl, int askr) {
    if (l >= askr || r <= askl) return INT64_MAX;

    if (l >= askl && r <= askr) return tree[v];

    ll mid = (l + r) / 2;
    return min(get(v * 2 + 1, l, mid, askl, askr), get(v * 2 + 2, mid, r, askl, askr));
}
ll check(ll lft) {
    ll vl = 0;

    ll pr = 0, s = 0, ans= 0;
    ll mx = 0, mn = 0;
    vector<ll> kt;
    vector<ll> added;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] < lft) {
            sort(kt.begin(), kt.end());
            
            for (int t = 0; t < s - k + 1; t++) {
                added.push_back(kt[t]);
            }
            vl += (s - k + 1);
            s = 0;
            pr = 0;
            kt.clear();
        }
        else {
            s++;
            kt.push_back(vec[i]);
            pr = 1;
        }
    }

    sort(added.begin(), added.end());
    mn = INT64_MAX;
    for (int i = 0; i < q && i < added.size(); i++) {
        mx = max(mx, added[i]);
        mn = min(mn, added[i]);
    }
    if (added.size() >= q) return mx - mn;
    else {
        return -1;
    }
}

int main() {
    fastInp;

    cin >> n >> k >> q;
    vec.resize(n);

    for (int i = 0; i < n; i++) cin >> vec[i];
    vec.push_back(-1);
    srt = vec;
    sort(srt.begin(), srt.end());
    ll mxNm = 0, ans = INT64_MAX;
    for (int i = 1; i < srt.size(); i++) {
        int l = i, r = n - 1;

        if (check(srt[i]) != -1) {
            ans = min(ans, check(srt[i]));
        }
    }

    cout << ans;

    return 0;
}

