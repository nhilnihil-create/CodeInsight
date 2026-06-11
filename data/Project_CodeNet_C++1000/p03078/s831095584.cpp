#include <bits/stdc++.h>
#define H ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ld long double
using namespace std;
const ll  mod = 998244353;


int main()
{
    H
    int x, y ,z , k;
    cin >> x >> y >> z >> k;
    ll a[x], b[y], c[z];
    vector<ll> v, ans;
    for (int i = 0; i < x; i++) cin >> a[i];
    for (int i = 0; i < y; i++) cin >> b[i];
    for (int i = 0; i < z; i++) cin >> c[i];
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            v.push_back(a[i] + b[j]);
        }

    }
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < min(k, (int)v.size()); i++){
        for (int j = 0; j < z; j++){
            ans.push_back(v[i] + c[j]);
        }
    }
    sort(ans.rbegin(), ans.rend());
    for (int i = 0; i < k; i++){
        cout << ans[i] << '\n';
    }

    return 0 ;
}
