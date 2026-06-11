#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for (int (i)=0; (i) < (n); (i)++)

int main()
{
    ll a, b, c; cin >> a >> b >> c;
    vector<ll> cost(3, 0);
    cost[0] = abs(b - a);
    cost[1] = abs(c - a);
    cost[2] = abs(c - b);
    sort(cost.begin(), cost.end());
    ll ans = cost[0] + cost[1];
    cout << ans << endl;
    

}
