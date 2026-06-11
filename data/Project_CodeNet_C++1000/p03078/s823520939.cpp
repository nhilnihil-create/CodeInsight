#include <bits/stdc++.h>

using namespace std;
#define ll long long


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<ll> a(x), b(y), c(z);
    for (auto &x:a) cin >> x;
    for (auto &x:b) cin >> x;
    for (auto &x:c) cin >> x;

    vector<ll> temp(x * y);
    int indx = 0;
    for (int i = 0; i < x; i++) for (int j = 0; j < y; j++) temp[indx++] = a[i] + b[j];

    sort(temp.rbegin(), temp.rend());

    temp.resize(min(k, (int) temp.size()));

    vector<ll> res(temp.size() * z);
    indx = 0;
    for (int i = 0; i < temp.size(); i++) for (int j = 0; j < z; j++) res[indx++] = temp[i] + c[j];

    sort(res.rbegin(), res.rend());
    for (int i = 0; i < k; i++) cout << res[i] << '\n';


    return 0;
}