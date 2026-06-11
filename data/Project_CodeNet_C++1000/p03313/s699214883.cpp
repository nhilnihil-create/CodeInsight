#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 1e6 + 100;
vector<pair<ll, ll>> bst[SIZE];
vector<ll> pref;

int main()
{
    fastInp;

    ll n;
    cin >> n;
    ll sz = (1ll << n);
    vector<ll> vec(sz);
    for (int i = 0; i < vec.size(); i++) {
        cin >> vec[i];
        bst[i].push_back({vec[i], i});
    }

    pref.resize(sz);
    for (int i = 1; i < sz; i++) {
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                ll xr = (i) ^ (1ll << j);
                for (auto cur : bst[xr]) bst[i].push_back(cur);
            }
        }
        sort(bst[i].rbegin(), bst[i].rend());
        auto it = unique(bst[i].begin(), bst[i].end());
        bst[i].erase(it, bst[i].end());
        bst[i].resize(2);
        pref[i] = bst[i][0].first + bst[i][1].first;
    }

    for (int i = 2; i < pref.size(); i++) pref[i] = max(pref[i], pref[i - 1]);

    for (int i = 1; i < pref.size(); i++) cout << pref[i] << "\n";
    return 0;    
}