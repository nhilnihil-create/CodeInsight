#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main(){
    Hello
    ll x, y, z, k;
    cin >> x >> y >> z >> k;
    ll a[x], b[y], c[z];
    for(int i = 0; i < x; i++) cin >> a[i];
    for(int i = 0; i < y; i++) cin >> b[i];
    for(int i = 0; i < z; i++) cin >> c[i];
    sort(a, a + x);
    sort(b, b + y);
    sort(c, c + z);
    reverse(a, a + x);
    reverse(b, b + y);
    reverse(c, c + z);
    vector<ll> v;
    for(ll i = 0; i < x; i++){
        for(ll j = 0; j < y; j++){
            for(ll d = 0; d < z; d++){
                if((i + 1) * (j + 1) * (d + 1) <= k)
                    v.push_back(a[i] + b[j] + c[d]);
                else break;
            }
        }
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for(int i = 0; i < k; i++)
        cout << v[i] << endl;
    return 0;
}
