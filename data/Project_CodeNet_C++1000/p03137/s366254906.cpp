#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> x(m), d(m);

    for (int i = 0; i < m; i++) cin >> x[i];

    if (n >= m) {
        cout << 0 << endl;
        return 0;
    }
    sort(x.begin(), x.end());

    int ans = 0;    
    for (int i = 0; i < m - 1; i++) {
        d[i] = x[i+1] - x[i];
        ans += d[i];
    }

    sort(d.begin(), d.end(), greater<int>());

    for (int i = 0; i < n - 1; i++) {
        ans -= d[i];
    }

    cout << ans << endl;

}