#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<bool> solution;
ll n, res = -10000000000000;

void solve2(vector<vector<bool>> &stores, vector<vector<ll>> &prices) {
    ll result = 0;
    for (ll i=0; i<n; i++) {
        ll counts = 0;
        for (ll j=0; j<10; j++) if (solution[j] && stores[i][j]) counts++;
        result+=prices[i][counts];
    }
    res = max(res,result);
    return;
}

void solve(vector<vector<bool>> &stores, vector<vector<ll>> &prices) {
    if (solution.size()==10) {
		ll counts = 0;
		for (auto i : solution) if (i) counts++;
        if (counts>0) solve2(stores,prices);
        return;
    }
    solution.push_back(0);
    solve(stores,prices);
    solution.pop_back();
    solution.push_back(1);
    solve(stores,prices);
    solution.pop_back();
    return;
}

int main() {
    cin >> n;
	bool temp;
    vector<bool> srow(10,0);
    vector<vector<bool>> stores(n,srow);
    vector<ll> prow(11,0);
    vector<vector<ll>> prices(n,prow);
    for (ll i=0; i<n; i++) for (ll j=0; j<10; j++) {
		cin >> temp;
		stores[i][j] = temp;
	}
    for (ll i=0; i<n; i++) for (ll j=0; j<11; j++) cin >> prices[i][j];
    solve(stores,prices);
    cout << res;
    return 0;
}