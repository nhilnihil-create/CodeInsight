#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int x, y, z, k; cin >> x >> y >> z >> k;
    vector<ll> a(x), b(y), c(z);
    for (int i = 0; i < x; i++) cin >> a[i];
    for (int i = 0; i < y; i++) cin >> b[i];
    for (int i = 0; i < z; i++) cin >> c[i];
    
    vector<ll> v(x*y);
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            v[y*i+j] = a[i] + b[j];
        }
    }

    sort(v.begin(), v.end(), greater<ll>());
    vector<ll> w(k*z);
    for (int i = 0; i < z; i++)
    {
        for (int j = 0, nnn=min(k, x*y); j < nnn; j++)
        {
            w[i*k+j] = c[i] + v[j];  
        }
    }
    sort(w.begin(), w.end(), greater<ll>());
    for (int i = 0; i < k; i++)
    {
        cout << w[i] << '\n';
    }
}