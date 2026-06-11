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

void printVector(const vector<ll>& vec) {
    for (ll value : vec) {
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

    ll N; cin >> N;
    vector<ll> v(N), a, b;
    deque<pair<ll,ll> > deqa, deqb;

    rep(i, N) cin >> v[i];

    rep(i, N) {
        if (i % 2 == 0) { a.push_back(v[i]); }
        else if (i % 2 == 1) { b.push_back(v[i]); }
    }

    sort(all(a));
    sort(all(b));

    if (N == 2) {
        if (v[0] == v[1]) {
            cout << 1 << endl;
            return 0;
        }
        else {
            cout << 0 << endl;
            return 0;
        }
    }

    ll jj = 1;

    rep(i, N / 2 - 1) {
        if (a[i] == a[i + 1]) { ++jj; }
        else {
            deqa.push_back(make_pair(jj,a[i]));
            jj = 1;
        }
    }

    if (deqa.size() == 0) deqa.push_back(make_pair(jj, a[0]));
    if (a[N / 2 - 1] != a[N / 2 - 2]) deqa.push_back(make_pair(1, a[N / 2 - 1]));

    jj = 1;

    rep(i, N / 2 - 1) {
        if (b[i] == b[i + 1]) { ++jj; }
        else {
            deqb.push_back(make_pair(jj, b[i]));
            jj = 1;
        }
    }

    if (deqb.size() == 0) deqb.push_back(make_pair(jj, b[0]));
    if (b[N / 2 - 1] != b[N / 2 - 2]) deqb.push_back(make_pair(1, b[N / 2 - 1]));

    sort(all(deqa));
    sort(all(deqb));

    if (deqa[deqa.size() - 1].second == deqb[deqb.size() - 1].second) {
        if (deqa.size() == 1 && deqb.size() == 1) { cout << N/2 << endl; }
        else if (deqa.size() > 1 && deqb.size() == 1) { cout << N - deqa[deqa.size() - 2].first - deqb[deqb.size() - 1].first << endl; }
        else if (deqa.size() == 1 && deqb.size() > 1) { cout << N - deqa[deqa.size() - 1].first - deqb[deqb.size() - 2].first << endl; }
        else { cout << min(N - deqa[deqa.size() - 1].first - deqb[deqb.size() - 2].first, N - deqa[deqa.size() - 2].first - deqb[deqb.size() - 1].first) << endl; }
    }
    else {
        cout << N - deqa[deqa.size() - 1].first - deqb[deqb.size() - 1].first << endl;
    }

}