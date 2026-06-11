#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

bool isOk(int index, int key, vector<int> &a) {
    if (a[index] >= key) {
        return true;
    } else {
        return false;
    }
}

int binary_search(int key, vector<int> &a) {
    int ng = -1;
    int ok = (int)a.size();

    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOk(mid, key, a)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    return ok;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    ll ans = 0;
    sort(a.begin(), a.end());
    sort(c.begin(), c.end());
    for (int i = 0; i < n; ++i) {
        ll upper = binary_search(b[i], a);
        ll lower = n - binary_search(b[i] + 1, c);
        ans += upper * lower;
    }
    cout << ans << endl;

    return 0;
}
