#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for(int (i)=0; (i) < (n); (i)++)

int main()
{
    ll N, X; cin >> N >> X;
    vector<ll> m(N, 0);
    ll sum = 0;
    rep(i,N) {
        cin >> m[i];
        sum += m[i];
    }
    sort(m.begin(), m.end());
    ll ans = N;
    X -= sum;
    ans += (X / m[0]);
    cout << ans << endl;
    




}
