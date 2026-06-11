#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
typedef tuple<string, int, int> sii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 105;
int n, p;
string s;
sii a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s >> p;
        a[i] = {s, p, i};
    }
    sort(a + 1, a + n + 1, [](sii &a, sii &b) {
        string s1 = get<0>(a);
        string s2 = get<0>(b);
        int i1 = get<1>(a);
        int i2 = get<1>(b);
        if (s1 == s2)
            return i1 > i2;
        return s1 < s2;
    });
    for (int i = 1; i <= n; ++i) {
        cout << get<2>(a[i]) << endl;
    }

    return 0;
}
