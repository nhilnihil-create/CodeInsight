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

    ll N, M; cin >> N >> M;
    vector<pair<ll, ll> > pa(M);
    ll p, y;
    map<ll, pair<ll, ll> > ma;
    map<pair<ll, ll>, string> ma2;

    rep(i, M) {
        cin >> p >> y;
        pa[i] = make_pair(p, y);
        ma[i] = pa[i];
    }

    sort(all(pa));

    ll jj = 0;

    rep(i, M) {
        ++jj;
        string a=to_string(pa[i].first);
        if (a.size() == 1) { a = "00000"+a; }
        else if (a.size() == 2) { a = "0000" + a; }
        else if (a.size() == 3) { a = "000" + a; }
        else if (a.size() == 4) { a = "00" + a; }
        else if (a.size() == 5) { a = "0" + a; }
        string b = to_string(jj);
        if (b.size() == 1) { b = "00000" + b; }
        else if (b.size() == 2) { b = "0000" + b; }
        else if (b.size() == 3) { b = "000" + b; }
        else if (b.size() == 4) { b = "00" + b; }
        else if (b.size() == 5) { b = "0" + b; }
        ma2[pa[i]]=a + b;
        if (i < pa.size() - 1 && pa[i].first != pa[i + 1].first) jj = 0;
    }

    rep(i, M) {
        cout << ma2[ma[i]] << endl;
    }

}