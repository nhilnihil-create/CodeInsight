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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll H, W, N;
    cin >> H >> W >> N;
    vec obstacles(H, inf);
    Rep (i, N) {
        ll X, Y;
        cin >> X >> Y;
        X--; Y--;
        chmin(obstacles[X], Y);
   }

//    Rep (i, H) {
//        cout << obstacles[i] << " \n"[i==H-1];
//    }

    ll now = 0;
    Rep (i, H-1) {
        // cout << now << " " << obstacles[i] << "\n";
        if (obstacles[i+1] <= now) {
            cout << i+1 << "\n";
            return 0;
        }
        now++;
        if (obstacles[i+1] == now) now--;
    }

    cout << H << "\n";
}