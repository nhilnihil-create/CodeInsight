#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;

ll a[N], b[N], c[N];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll x, y, z, k;
    cin >> x >> y >> z >> k;
    for(int i = 0; i < x; i++){
        cin >> a[i];
    }
    for(int i = 0; i < y; i++){
        cin >> b[i];
    }
    for(int i = 0; i < z; i++){
        cin >> c[i];
    }
    vector<ll> v;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            v.push_back(0LL + a[i] + b[j]);
        }
    }
    sort(v.begin(), v.end());
    vector<ll> ans;
    for(int i = v.size() - 1; i >= max((int)v.size() - 3005, 0); i--){
        for(int j = 0; j < z; j++){
            // cout << v[i] + c[j] << '\n';
            ans.push_back(v[i] + c[j]);
        }
    }
    // return 0;
    sort(ans.rbegin(), ans.rend());
    for(int i = 0; i < k; i++){
        cout << ans[i] << '\n';
    }

    return 0;
}
