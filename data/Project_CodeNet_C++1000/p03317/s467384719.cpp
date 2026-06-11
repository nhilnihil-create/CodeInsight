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
#include <numeric>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi >;
using vl = vector<ll>;
using vvl = vector<vl >;
using pairi = pair<int, int>;
using pairl = pair<ll, ll>;

#define TR ","
#define TS " "
#define rep(i,N) for(ll i=0;i<(ll)N;++i)
#define rpt(i,a,b) for(ll i=a;i<(ll)b;++i)
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

    ll N, K, P; cin >> N >> K;
    vl a(N);
    rep(i, N) cin >> a[i];
    rep(j, N) {
        if (a[j] == 1) {
            P = j + 1;
        }
    }
    
    if (N == K) {
        cout << 1 << endl;
    }
    else if (P == 1 || P == N) {
        if ((N - 1) % (K - 1) == 0) {
            cout << (N - 1) / (K - 1) << endl;
        }
        else {
            cout << (N - 1) / (K - 1) + 1 << endl;
        }
    }
    else if ((N - K) % (K - 1) == 0) {
        cout << (N - K) / (K - 1) + 1 << endl;
    }
    else if ((P - 1) / (K - 1) == 0 || (N - P) / (K - 1) == 0) {
        if ((N - K) % (K - 1) == 0) {
            cout << (N - K) / (K - 1) + 1<< endl;
        }
        else {
            cout << (N - K) / (K - 1) + 2 << endl;
        }
    }
    else {
        if ((P - 1) % (K - 1) == 0 && (N - P) % (K - 1) == 0) {
            cout << (P - 1) / (K - 1) + (N - P) / (K - 1) << endl;
        }
        else if ((P - 1) % (K - 1) != 0 && (N - P) % (K - 1) == 0) {
            cout << (P - 1) / (K - 1) + (N - P) / (K - 1) + 1 << endl;
        }
        else if ((P - 1) % (K - 1) == 0 && (N - P) % (K - 1) != 0) {
            cout << (P - 1) / (K - 1) + (N - P) / (K - 1) + 1 << endl;
        }
        else {
            cout << (P - 1) / (K - 1) + (N - P) / (K - 1) + 2 << endl;
        }
    }
}