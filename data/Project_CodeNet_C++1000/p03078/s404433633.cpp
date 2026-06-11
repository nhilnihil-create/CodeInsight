#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define endl '\n'
int main()
{
    Hello
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    ll a[x + 5], b[y + 5], c[z + 5];
    for(int i = 0; i < x; i++) cin >> a[i];
    for(int i = 0; i < y; i++) cin >> b[i];
    for(int i = 0; i < z; i++) cin >> c[i];
    vector<ll> pro, res;
    for(int i = 0; i < x; i++)
        for(int j = 0; j < y; j++)
            pro.push_back(a[i] + b[j]);
    sort(pro.rbegin(), pro.rend());
    for(int i = 0; i < min(k, (int)pro.size()); i++)
        for(int j = 0; j < z; j++)
            res.push_back(pro[i] + c[j]);
    sort(res.rbegin(), res.rend());
    for(int i = 0; i < k; i++)
        cout << res[i] << endl;
    return 0;
}