#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int x, y, z, k;    cin >> x >> y >> z >> k;
    vector<ll> a(x), b(y), c(z), v, u, s;
    for (int i = 0; i < x; i++)
        cin >> a[i];
    for (int i = 0; i < y; i++) 
        cin >> b[i];
    for (int i = 0; i < z; i++)
        cin >> c[i];

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++)
            v.push_back(a[i] + b[j]);
    }
    sort(v.begin(), v.end(), greater<ll>());
    sort(c.begin(), c.end(), greater<ll>());
    for (int i = 0; i < min(k, x*y); i++)
        u.push_back(v[i]);

    for (int i = 0; i < u.size(); i++) {
        for (int j = 0; j < z; j++)
            s.push_back(u[i] + c[j]);
    }

    sort(s.begin(), s.end(), greater<ll>());
    for (int i = 0; i < k; i++)
        cout << s[i] << endl;
    return 0;
}