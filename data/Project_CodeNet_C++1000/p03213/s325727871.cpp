#include <iostream>
#include <map>
#include <vector>
#define rep(i,n) for(int (i)=0;(i)<(n);++(i))
#define all(x) (x).begin(),(x).end()
#define dump(x) cout << #x << " = " << (x) << endl

using namespace std;
using ll = long long;


vector<pair<ll, ll>> prime_factorize(ll n) {
    vector<pair<ll, ll>> res;

    for (ll a = 2; a * a <= n; ++a) {
        if (n % a != 0) continue;

        ll ex = 0;
        while (n % a == 0) {
            ++ex;
            n /= a;
        }
        res.emplace_back(a, ex);
    }

    if (n != 1) res.emplace_back(n, 1ll);

    return res;
}


int n;
map<ll, int> sisuu;

ll rec(map<ll, int>::const_iterator p, ll mul) {
    if (p == sisuu.cend()) {
        if (mul == 1) return 1;
        else return 0;
    }

    ll res = 0;
    for (int i = 0; i < p->second + 1; ++i) {
        if (mul % (i + 1) != 0) continue;
        res += rec(++p, mul / (i + 1));
        --p;
    }

    return res;
}



int main() {
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        auto ps = prime_factorize(i);
        for (auto it: ps) sisuu[it.first] += it.second;
    }

    cout << rec(sisuu.cbegin(), 75) << endl;
}