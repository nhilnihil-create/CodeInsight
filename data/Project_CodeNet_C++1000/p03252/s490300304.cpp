#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <utility> 
#include <tuple> 
#include <cstdint> 
#include <cstdio> 
#include <map> 
#include <queue> 
#include <set> 
#include <stack> 
#include <deque> 
#include <unordered_map> 
#include <unordered_set> 
#include <bitset> 
#include <cctype> 
#include <cmath>
#include <iomanip>
#include <ctype.h>

using namespace std;
using ll = long long;
using PAIR = pair<int, int>;
using PAIRLL = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;

#define TR ","
#define fi first
#define se second
#define rep(i,N) for(ll i=0;i<(ll)N;++i)
#define repe(i,a,b) for(ll i=a;i<(ll)b;++i)
#define all(v) v.begin(), v.end()
#define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define INF 100000000

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll x, ll y) {
    return x / gcd(x, y) * y;
}

ll waz = 76543217;

ll inv(ll x) {
    if (x == 1) { return 1; }
    if (x == 0) { return 0; }
    else {
        ll a = (waz - inv(waz % x) * (waz / x)) % waz;
        if (a >= 0) { return a; }
        else { return waz + a; }
    }
}

void printVector(const vector<int>& vec) {
    for (int value : vec) {
        cout << value << " ";
    }
    cout << endl;
}

vector<ll> p;

ll phi(ll x) {
    ll a = x;
    ll b = x;
    for (ll k = 0; k != p.size(); ++k) {
        if (a % p[k] == 0) {
            while (a % p[k] == 0) {
                a /= p[k];
            }
            b = b / p[k] * (p[k] - 1);
        }
        if (a == 1) { break; }
    }
    return b;
}

bool my_compare(pair<string, int> a, pair<string, int> b) {
    if (a.first != b.first) {
        return a.first < b.first;
    }

    if (a.second != b.second) {
        return a.second > b.second;
    }
    else {
        return true;
    }
}

int main()
{
    IO;

    string S, T; cin >> S >> T;

    string SC = S, TC = T;

    sort(all(SC));
    sort(all(TC));

    deque<ll> deqs, deqt;

    ll jj = 1;
    rep(i, SC.size()-1) {
        if (SC[i] == SC[i + 1]) {
            ++jj;
        }
        else {
            deqs.push_back(jj);
            jj = 1;
        }
    }
    if (SC[SC.size() - 2] == SC[SC.size() - 1]) deqs.push_back(jj);

    jj = 1;
    rep(i, TC.size() - 1) {
        if (TC[i] == TC[i + 1]) {
            ++jj;
        }
        else {
            deqt.push_back(jj);
            jj = 1;
        }
    }
    if (TC[TC.size() - 2] == TC[TC.size() - 1]) deqt.push_back(jj);

    sort(all(deqs));
    sort(all(deqt));

    if (deqs.size() != deqt.size()) {
        cout << "No" << endl;
        return 0;
    }
    else {
        ll a = deqs.size();
        rep(i, a) {
            if (deqs[i] != deqt[i]) {
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
        return 0;
    }


}