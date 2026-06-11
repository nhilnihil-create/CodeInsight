#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int main() {

    int N, x;
    cin >> N >> x;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = N-1;

    rep(i, N) {
        x -= a[i];
        if (x < 0) {
            ans = i;
            break;
        } else if (x == 0) {
            ans = i+1;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}