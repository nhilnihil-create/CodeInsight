#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
#define REP(i,n) for (int i = 0; i < n; ++i)
#define FOR(i,m,n) for (int i = m; i < n; ++i)
#define ALL(x) x.begin(), x.end()

int K;
vl cand;

ll S(ll x) {
    ll res = 0;
    while (x) {
        res += x%10;
        x /= 10;
    }
    return res;
}

ld T(ll x) {
    return (ld)x/S(x);
}

int main() {

    ll k = 1;
    ll n = 0;
    REP (i, 15) {
        FOR (a, 1, 200) cand.push_back(a*k+n);
        k *= 10;
        n = n * 10 + 9;
    }

    sort(ALL(cand));

    cin >> K;
    int i = 0;
    while (K) {
        // if (cand[i] > 1e15) break;
        if (cand[i] == cand[i+1]) {
            i++;
            continue;
        }
        bool res = true;
        FOR (j, i+1, cand.size()) {
            res &= (T(cand[i]) <= T(cand[j]));
        }
        if (res) {
            cout << cand[i] << endl;
            K--;
        }
        i++;
    }
}