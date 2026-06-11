#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    string S;
    cin >> S;
    ll X, Y, l = 0;
    cin >> X >> Y;
    vector<ll> ax, ay;
    ll x0 = -1, y0 = 0;
    bool fx = true;
    auto pushL = [&]() {
            if ( fx ) {
                if ( x0 < 0 ) x0 = l;
                else if ( l > 0 ) ax.push_back(l);
            } else {
                if ( l > 0 ) ay.push_back(l);
            }
            fx = !fx;
            l = 0;
    };
    for ( int i = 0; i < S.size(); i++ ) {
        if ( S[i] == 'F' ) l++;
        else {
            pushL();
        }
    }
    if ( S.back() == 'F' ) pushL();

    auto canMove = [](ll dist, vector<ll> x) -> bool {
        unordered_set<ll> p, pp;
        p.insert(0);
        for ( ll dx : x ) {
            p.swap(pp);
            p.clear();
            for ( ll cp : pp ) {
                p.insert(cp + dx);
                p.insert(cp - dx);
            }
        }
        return p.find(dist) != p.end();
    };

    bool ans = canMove(X-x0, ax) && canMove(Y, ay);
    return ans;
}

int main() {
    string ans = solve() ? "Yes" : "No";
    cout << ans << "\n";
    return 0;
}