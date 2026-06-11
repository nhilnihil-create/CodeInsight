#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

int main() {
    ll n, t; cin >> n >> t;
    vector<ll> cand;
    for (int i = 0; i < n; ++i) {
        ll c, ti; cin >> c >> ti;
        if (ti <= t) cand.push_back(c);
    }
    sort(cand.begin(), cand.end());
    if (cand.size() == 0) {
        cout << "TLE" << endl;
    }
    else {
        cout << cand[0] << endl; 
    }
}