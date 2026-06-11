#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++)cin >> x[i] >> y[i];
    ll ans = 4e18 + 10000;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                for(int l = 0; l < n; l++) {

                    int x1 = x[i], y1 = y[j], x2 = x[k], y2 = y[l];
                    if(x1 == x2 || y1 == y2)continue;
                    if(x1 > x2)swap(x1, x2);
                    if(y1 > y2)swap(y1, y2);

                    int cnt = 0;
                    for(int m = 0; m < n; m++){
                        if(x1 <= x[m] && x[m] <= x2 && y1 <= y[m] && y[m] <= y2)cnt++;
                    }
                    if(cnt >= t)ans = min(ans, (ll)(x2 - x1) * (y2 - y1));
                }
            }
        }
    }

    cout << ans << endl;
}
