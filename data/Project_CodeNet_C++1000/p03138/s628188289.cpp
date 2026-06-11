#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <tuple>
#include <cstring>
#include <map>
#include <iomanip>
#include <ctime>
#include <complex>
#include <cassert>
#include <climits>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define _ << " " <<
#define all(X) (X).begin(), (X).end()
#define len(X) (X).size()
#define Pii pair<int, int>
#define Pll pair<ll, ll>
#define Tiii tuple<int, int, int>
#define Tlll tuple<ll, ll, ll>

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), bit(40);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < 40; j++) {
            bit[j] += bool((1LL << j) & a[i]);
        }
    }

    ll ans = 0, val = 0;
    for (int i = 39; i >= 0; i--) {
        if (bit[i] >= n - bit[i] || val + (1LL << i) > k) {
            ans += bit[i] * (1LL << i);
        }
        else {
            ans += (n - bit[i]) * (1LL << i);
            val += (1LL << i);
        }
        cerr << ans _ val << endl;
    }

    cout << ans << endl;

    for (int i = 0; i < 40; i++) cerr << bit[i];

}
