#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <cassert>
#include <random>
#include <tuple>
#include <cstdint>
#include <complex>
#include <bitset>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
typedef long long ll;
typedef pair<int, int> pint;

const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
    int n, k; cin >> n >> k;
    vector<pint> sushi(n);
    rep(i, n) {
        int t, d; cin >> t >> d;
        sushi[i] = make_pair(d, t);
    }
    sort(sushi.rbegin(), sushi.rend());

    vector<int> residue;
    map<int, int> mp;

    ll base = 0;
    int kind = 0;
    rep(i, k) {
        int t = sushi[i].second;
        int d = sushi[i].first;
        if (!mp.count(t)) {
            mp[t]++;
            base += d;
            kind++;
        } else {
            residue.push_back(d);
            base += d;
        }
    }

    ll ans = base + ll(kind) * ll(kind);
    sort(residue.begin(), residue.end());
    int j = 0;

    for (int i = k; i < n; i++) {
        int t = sushi[i].second;
        int d = sushi[i].first;
        if (mp.count(t)) continue;
        if (j >= residue.size()) break;
        base -= residue[j];
        j++;
        base += d;
        kind++;
        mp[t]++;
        ans = max(ans, base + ll(kind) * ll(kind));
    }


    cout << ans << endl;



    return 0;
}


    
