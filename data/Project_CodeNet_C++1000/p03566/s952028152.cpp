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

    ll N;
    cin >> N;
    vec t(N), v(N);
    ll s = 0;
    Rep (i, N) {
        cin >> t[i];
        t[i] *= 2;
        s += t[i];
    }
    Rep (i, N) {
        cin >> v[i];
        v[i] *= 2;
    }

    vec graph(s+1, inf);
    ll tmp = 0;
    Rep (i, N) {
        Rep (j, t[i]+1) {
            chmin(graph[tmp+j], v[i]);
        }
        tmp += t[i];
    }

    graph[0] = 0;
    Rep (i, s) {
        chmin(graph[i+1], graph[i] + 1);
    }

    reverse(graph.begin(), graph.end());
    graph[0] = 0;
    Rep (i, s) {
        chmin(graph[i+1], graph[i] + 1);
    }

    reverse(graph.begin(), graph.end());
    // Rep (i, s+1) {
    //     cout << graph[i] << " \n"[i==s];
    // }

    double ans = 0;
    Rep (i, s) {
        ans += (double)(graph[i] + graph[i+1])/2.0;
    }

    cout << fixed << setprecision(5) << ans/4 << "\n";
    
    
}