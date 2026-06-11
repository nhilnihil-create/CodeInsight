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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    reverse(all(a));
    if (a[0] != 2) {
        cout << -1 << endl;
        return 0;
    }

    ll mn = 2, mx = 3;
    for (int i = 0; i < n - 1; i++) {
        mn = ((mn - 1) / a[i + 1] + 1) * a[i + 1];
        mx = (mx / a[i + 1] + 1) * a[i + 1] - 1;
        //cerr << mn _ mx << endl;
        if (mx < mn) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << mn _ mx << endl;
}
