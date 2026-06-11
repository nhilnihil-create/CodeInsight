#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 1e5 + 5;
int n, q, l, r;
string s;
int psum[N];
int main() {
    cin >> n >> q;
    cin >> s;
    int sum = 0;
    for (int i = 1; i < n; ++i) {
        if (s[i] == 'C' && s[i - 1] == 'A')
            ++sum;
        psum[i + 1] = sum;
    }
    for (int i = 0; i < q; ++i) {
        cin >> l >> r;
        cout << psum[r] - psum[l] << endl;
    }
    return 0;
}
