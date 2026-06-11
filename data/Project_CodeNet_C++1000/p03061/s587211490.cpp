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
#define rep(i,N) for(int i=0;i<(int)N;++i)
#define all(v) v.begin(), v.end()
#define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

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
    ll c = x;

    for (ll k = 0; k != p.size(); ++k) {
        if (a % p[k] == 0) {
            while (a % p[k] == 0) {
                a /= p[k];
            }
            b = b / p[k] * (p[k] - 1);
        }
        if (a == 1) { break; }
        if (p[k] > sqrt(c)) { break; }
    }
    if (a > 1) { return b / a * (a - 1); }
    else { return b; }
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

    int N; cin >> N;
    vector<ll> A(N), le(N), ri(N), lr(N);
    rep(i, N) cin >> A[i];

    le[0] = A[0];

    for(int i=1; i<N; ++i){
        le[i] = gcd(le[i-1], A[i]);
    }

    ri[N - 1] = A[N - 1];

    for (int i = 1; i < N; ++i) {
        ri[N-i-1] = gcd(ri[N-i], A[N-1-i]);
    }

    lr[0] = ri[1]; lr[N - 1] = le[N - 2];

    for (int i = 1; i < N - 1; ++i) {
        lr[i] = gcd(ri[i+1], le[i-1]);
    }

    sort(lr.begin(), lr.end());

    cout << lr[N - 1] << endl;
}