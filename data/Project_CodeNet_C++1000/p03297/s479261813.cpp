#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <fstream>
#include <cmath>
#include <random>
#include <complex>
#include <functional>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;
typedef vector<ll> vec;
typedef vector<vec> mat;

const ll inf = 1LL << 60;

template<class T> inline void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}
template<class T> inline void chmax(T& a, T b) {
    if (a < b) {
        a = b;
    }
}

ll GCD (ll a, ll b) { return b ? GCD(b, a%b) : a;}

ll LCM (ll a, ll b) {
    ll g = GCD (a, b);
    return a * b / g;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll T;
    cin >> T;
    while (T--) {
        ll A, B, C, D;
        cin >> A >> B >> C >> D;
        bool ans;
        if (A < B) ans = false;
        else if (B > D) ans = false;
        else if (C >= B) ans = true;
        else if (B - GCD(B, D) + A % GCD(B, D) > C) ans = false;
        else ans = true;

        if (ans) cout << "Yes\n";
        else cout << "No\n"; 
    }
    
}