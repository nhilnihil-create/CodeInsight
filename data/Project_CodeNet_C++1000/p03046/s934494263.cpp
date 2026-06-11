#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ld long double
#define pb push_back
#define f first
#define se second
 
 
using namespace std;
 
const int N = 5e5 + 123; 


ll m, k, pw[30];
bool is[N];
vector <ll> a, b;

 
int main() {
    cin >> m >> k;
    ll t = 1;
    for (ll i = 0; i <= 20; i++) {
        pw[i] = t;
        t *= 2;
    }
    if (k > pw[m] - 1)
        return cout << -1, 0;
    if (m == 0)
        return cout << "0 0", 0;
    if (m == 1 && k == 0)
        return cout << "0 0 1 1", 0;
    if (m == 1)
        return cout << -1, 0;
    if (k == 0) {
        for (int i = 0; i < pw[m]; i++)
            cout << i << " ";
        for (int i = pw[m] - 1; i >= 0; i--)
            cout << i << " ";
        return 0;
    }
    bool iss = 0;
    for (int i = 0; i < 20; i++)
        if (k == pw[i]) {
            if (k != 1) {
                b.pb(pw[i] + 1);
                b.pb(1);
                iss = 1;
                is[1] = is[pw[i] + 1] = 1;
            } else {
                b.pb(pw[1]);
                b.pb(pw[1] + 1);
                iss = 1;
                is[pw[1]] = is[pw[1] + 1] = 1;
            }
            break;
        }
    if (!iss) {
        for (int i = 0; i < 20; i++)
            if (1 & (k>>i)) {
                is[pw[i]] = 1;
                b.pb(pw[i]);
            }
    }
    is[k] = 1;
    for (int i = 0; i < b.size(); i++)
        a.pb(b[i]);
    for (int i = 0; i < pw[m]; i++)
        if (!is[i])
            a.pb(i);
    a.pb(k);
    for (int i = pw[m] - 1; i >= 0; i--)
        if (!is[i])
            a.pb(i);
    for (int i = b.size() - 1; i >= 0; i--)
        a.pb(b[i]);
    a.pb(k);
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    return 0; 
}
