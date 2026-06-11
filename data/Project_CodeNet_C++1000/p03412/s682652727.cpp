#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 1e5 * 2 + 100, INF = 1e9 + 10, MOD = 1e9 + 7;

vector<ll> vec, ans, cur;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<ll>> graph;
vector<ll> a, b;

void input() {
    ll n, l;
    cin >> n;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
}

void rand_test() {
    
}

ll sol() {
    ll xr = 0;
    for (int i = 29; i >= 1; i--) {
        ll curPw = (1ll << i);
        for (auto &cur : a) cur &= (curPw - 1);
        for (auto &cur : b) cur &= (curPw - 1);
        sort(b.begin(), b.end());
        ll curC = 0, t = curPw / 2;
        if (i == 1) {
            cout << "";
        }
        for (auto cur : a) {
            int l1, r1, l2, r2;
            int l = -1, r = b.size();
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if ((cur + b[mid]) >= t) {
                    r = mid;
                }
                else {
                    l = mid;
                }
            }

            l1 = r;

            l = -1, r = b.size();
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if ((cur + b[mid]) >= 2 * t) {
                    r = mid;
                }
                else {
                    l = mid;
                }
            }

            r1 = r;

            curC += (r1 - l1);

            l = -1, r = b.size();
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if ((cur + b[mid]) >= 3 * t) {
                    r = mid;
                }
                else {
                    l = mid;
                }
            }

            l2 = r;

            l = -1, r = b.size();
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if ((cur + b[mid]) >= 4 * t) {
                    r = mid;
                }
                else {
                    l = mid;
                }
            }

            r2 = r;

            curC += r2 - l2;
        }

        curC %= 2;
        xr |= (1ll << (i - 1)) * curC;
    }

    return xr;
}

ll brute() {
    ll xr = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) xr ^= (a[i] + b[j]);
    }

    return xr;
}
int main()
{
    fastInp;

    ll t;
    t = 1;

    while (t--) {
        input();
        cout << sol();
    }

    return 0;
}