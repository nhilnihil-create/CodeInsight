#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(long long)(n);++(i))
using ll = long long;
using P = pair<int, int>;
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "Yes\n2\n1 1\n1 1" << endl;
        return 0;
    }
    bool ok = false;
    int ansk = 0;
    for (int k=2; k<=n; ++k) {
        if (k*(k-1)/2 == n) {
            ansk = k;
            ok = true;
            break;
        }
    }
    if (!ok) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    cout << ansk << endl;
    vector<int> sum(ansk, 0);
    sum[0] = 1;
    for (int i=1; i<ansk; ++i) sum[i] = sum[i-1] + i;

    rep(i, ansk-1) {
        cout << ansk-1 << ' ';
        rep(j, i) {
            if (j) cout << ' ';
            cout << sum[i] + j;
        }
        for (int j=i; j<ansk-1; ++j) {
            if (j) cout << ' ';
            cout << sum[j]+i;
        }
        cout << endl;
    }

    cout << ansk-1 << ' ';
    rep(i, ansk-1) {
        if (i) cout << ' ';
        cout << sum[i]+i;
    }
    cout << endl;

}
