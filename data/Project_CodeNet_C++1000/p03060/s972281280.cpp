
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 21;
int n, sum;
int c[N], v[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < n; ++i) {
        int d = v[i] - c[i];
        if (d > 0)
            sum += d;
    }
    cout << sum << endl;

    return 0;
}

