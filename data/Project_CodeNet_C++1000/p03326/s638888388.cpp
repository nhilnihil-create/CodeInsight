#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

vector<ll> s(2);


int main() {
    s[0] = 1;   s[1] = -1;
    int n, m;  cin >> n >> m;
    vector<ll> x(n), y(n), z(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> z[i];

    ll ans = -1e18;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                vector<ll> v;
                for (int l = 0; l < n; l++) {
                    ll w = s[i] * x[l] + s[j] * y[l] + s[k] * z[l];
                    v.push_back(w);
                }
                sort(v.begin(), v.end(), greater<ll>());
                ll tmp = 0;
                for (int l = 0; l < m; l++)
                    tmp += v[l];
                ans = max(ans, tmp);
            }
        }
    }
    cout << ans << endl;
    return 0;
}