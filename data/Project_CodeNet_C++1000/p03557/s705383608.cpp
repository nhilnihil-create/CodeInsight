#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = signed long long int;
using P = pair<int, int>;

bool is_ok(ll key, ll val) {
    if (val >= key) return true;
    
    return false;
}

int binary_search(ll key, vector<ll> &tgt) {
    int ng = -1, ok = (int)tgt.size();
    int tmp;
    do {
        tmp = (ng + ok) / 2;
        if (is_ok(key, tgt.at(tmp))) ok = tmp;
        else ng = tmp;
    } while (abs(ok - ng) != 1);
    
    return ok; 
}

int main (void) {
    int N;
    cin >> N;
    vector<vector<ll>> abc(3, vector<ll>(N));
    rep(i, 3) rep(j, N) cin >> abc.at(i).at(j);
    rep(i, 3) sort(abc.at(i).begin(), abc.at(i).end());
    
    ll ans = 0;
    rep(i, N)  {
        ll key = abc.at(1).at(i);
        ll x = binary_search(key, abc.at(0));
        ll y = binary_search(key+1, abc.at(2));
        if (x > N || y > N) continue;
        ans += (x) * (N - y);

    }
    cout << ans << endl;
}
