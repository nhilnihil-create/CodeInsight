#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <math.h>
#include <queue>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define Sort(Array) sort(Array.begin(), Array.end())
#define rev(a) reverse(a.begin(), a.end())
#define out(ans) cout << ans << endl;
const int MOD = 1000000007;
const int INF = INT_MAX;








int main() {

    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    int x[N];
    rep(i,N) cin >> x[i];
    int y[M];
    rep(i,M) cin >> y[i];

    bool war = true;
    for (int z = -100; z <= 100; ++z) {
        bool flag = true;
        if (Y < z || z <= X) flag = false;
        rep(i,N) if (z <= x[i]) flag = false;
        rep(i,M) if (y[i] < z) flag = false;
        if (flag) war = false; 
    }

    if (war) cout << "War" << endl;
    else cout << "No War" << endl;

    return 0;
}




//              g++ -std=c++1z




