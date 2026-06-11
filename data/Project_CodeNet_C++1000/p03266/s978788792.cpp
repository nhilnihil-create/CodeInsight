#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PB push_back
#define MP make_pair

const int mxN = 2e5;
ll c[mxN + 1];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        c[i % k]++;
    }

    if (k & 1) cout << c[0] * c[0] * c[0] << "\n";
    else cout << c[0] * c[0] * c[0] + c[k / 2] * c[k / 2] * c[k / 2] << "\n";
}