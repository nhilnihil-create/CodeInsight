#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    ll x[n], y[n];
    vector<ll> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        vec[i] = x[i];
    }
    ll ret = -1;
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            ll H = max(y[i], y[j]);
            ll h = min(y[i], y[j]);
            int first = 0;
            int last = 1;
            while (last < n) {
                int count = 0;
                for (int k = 0; k < n; k++) {
                    if ((h <= y[k])&&(y[k] <= H)&&(vec[first] <= x[k])&&(x[k] <= vec[last])) count++;
                }
                if (count >= k) {
                    if ((ret == -1)||(ret > (H - h) * (vec[last] - vec[first]))) ret = (H - h) * (vec[last] - vec[first]);
                    first++;
                }
                else {
                    last++;
                }
            }
        }
    }
    cout << ret << endl;
    return 0;
}