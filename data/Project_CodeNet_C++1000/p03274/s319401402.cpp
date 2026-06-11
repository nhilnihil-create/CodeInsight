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
#define rep(i,N) for(ll i=0;i<(ll)N;++i)
#define repe(i,a,b) for(ll i=a;i<(ll)b;++i)
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

void printVector(const vector<int>& vec) {
    for (int value : vec) {
        cout << value << " ";
    }
    cout << endl;
}

int main()
{
    IO;

    ll N, K; cin >> N >> K;
    vector<ll> x(N);
    rep(i, N) cin >> x[i];

    deque<ll> deqpz, deqm;

    rep(i, N) {
        if (x[i] >= 0) deqpz.push_back(x[i]);
        else deqm.push_back(x[i]);
    }

    reverse(all(deqm));

    deque<ll> dist;

    if (deqpz.size() == 0) {
        cout << abs(deqm[K - 1]) << endl;
    }
    else if (deqm.size() == 0) {
        cout << deqpz[K - 1] << endl;
    }
    else {
        rep(i, K - 1) {
            if (i < deqm.size() && K - i - 2 < deqpz.size()) {
                dist.push_back(abs(deqm[i]) + deqpz[K - i - 2] - deqm[i]);
            }
            if (i < deqpz.size() && K - i - 2 < deqm.size()) {
                dist.push_back(deqpz[i] + deqpz[i] - deqm[K - i - 2]);
            }
        }

        sort(all(dist));
        cout << dist[0] << endl;
    }

}