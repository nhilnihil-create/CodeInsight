#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    int N;
    cin >> N;

    vector<int> a(N);
    rep(i, N) cin >> a[i];


    int mi = a[0], ma = a[0];
    for (int i = 1; i < N; ++i) {
        mi = min(mi, a[i]);
        ma = max(ma, a[i]);
    }

    cout << ma - mi << endl;

    return 0;
}