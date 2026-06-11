#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main() {
    int n;
    cin >> n;
    vector<int> t(n+1), x(n+1), y(n+1);
    t[0] = 0;
    x[0] = 0;
    y[0] = 0;

    for(int i=1; i<=n; i++) cin >> t[i] >> x[i] >> y[i];

    for(int i=1; i<=n; i++) {
        int l = abs(x[i] - x[i-1])+ abs(y[i] - y[i-1]);
        int div_t = t[i] - t[i-1];

        if(div_t < l) {
            cout << "No" << endl;
            return 0;
        }

        if((div_t - l) % 2 == 1 && div_t >= l) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}