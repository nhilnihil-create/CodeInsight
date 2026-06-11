#include <bits/stdc++.h>

using namespace std;
#define int long long
#define x first
#define y second
typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

mt19937 rand1(chrono::high_resolution_clock::now().time_since_epoch().count());
int randlr(int l, int r) {
    return rand1() % (r - l + 1) + l;
}

signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> not0(n, -1);

    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i ++) {
        if (a[i - 1] != 0) {
            not0[i] = i - 1;
        }

        else {
            not0[i] = not0[i - 1];
        }
    }

    int answ = 0;
    for (int i = 0; i < n; i ++) {
        int j = not0[i];
        answ += (i - j);
        int curr = a[i];
        int sum = a[i];
        while (j != -1) {
            sum += a[j];
            curr ^= a[j];
            //cout << i << ' ' << j << ' ' << sum << ' ' << curr << ' ' << a[j] << endl;
            if (sum != curr) break;
            answ += (j - not0[j]);
            j = not0[j];
        }
    }

    cout << answ;

    return 0;
}
