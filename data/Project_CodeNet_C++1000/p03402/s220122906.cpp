#include<bits/stdc++.h>

using namespace std;
using ll = long long int;
using lc = complex<double>;

int main(void) {
    constexpr ll MOD = 1e9 + 7;
    constexpr double PI = acos(-1);
    cout << fixed << setprecision(16);
    cin.tie(0); ios::sync_with_stdio(false);

    ll a, b;
    cin >> a >> b;
    vector<vector<ll>> res(100, vector<ll>(100));
    for(ll i=50; i<100; i++)
        for(ll j=0; j<100; j++)
            res[i][j] = 1;

    a--, b--;
    for(ll i=0; i<50 && a; i+=2)
        for(ll j=0; j<100 && a; j+=2)
            res[i][j] = 1, a--;
    for(ll i=51; i<100 && b; i+=2)
        for(ll j=0; j<100 && b; j+=2)
            res[i][j] = 0, b--;

    cout << "100 100" << endl;
    for(ll i=0; i<100; i++, cout << endl)
        for(ll j=0; j<100; j++)
            cout << (res[i][j] ? '.' : '#');

}
