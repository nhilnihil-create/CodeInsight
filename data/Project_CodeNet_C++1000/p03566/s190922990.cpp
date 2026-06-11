#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    cout << fixed << setprecision(16);

    ll n;
    cin >> n;
    vector<double> t(n+2), v(n+2);
    for(ll i=0; i<n; i++) cin >> t[i+1];
    for(ll i=0; i<n; i++) cin >> v[i+1];

    ll ts = accumulate(t.begin(), t.end(), 0ll);
    partial_sum(t.begin(), t.end(), t.begin());

    double s = 0, p = 0;
    for(ll i=0; i<=2*ts; i++) {
        double tc = 0.5*i;
        double k = p + 0.5;
        {
            ll j=0;
            while(t[j] < tc)
                k = min(k, (tc - t[j]) + v[j]), j++;
            k = min(k, v[j]);
            while(j < n+1)
                k = min(k, (t[j] - tc) + v[j+1]), j++;
        }
        s += (p + k) * 0.5 / 2;
        p = k;
    }
    cout << s << endl;
}
