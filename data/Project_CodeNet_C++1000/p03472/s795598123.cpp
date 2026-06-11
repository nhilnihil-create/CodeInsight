#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, h;
    cin >> n >> h;
    vector<int> b(n);
    int maxa = 0;
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        maxa = max(maxa, x);
        b[i] = y;
    }
    int cnt = 0;
    int sumb = 0;
    sort(b.begin(), b.end(), greater<int>());
    for (int i=0; i<n; i++) {
        if (sumb >= h) {
            cout << cnt << endl;
            return 0;
        }
        if (maxa >= b[i]) {
            break;
        }
        sumb += b[i];
        cnt++;
    }
    h -= sumb;
    cnt += (h + maxa -1) / maxa;
    cout << cnt << endl;
}