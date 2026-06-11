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

    ll n, m;
    cin >> n >> m;

    ll ans;
    if (n == 1) {
        if (m == 1) ans = 1;
        else if (m == 2) ans = 0;
        else ans = m - 2;
    }
    else if (n == 2) {
        ans = 0;
    }
    else {
        if (m == 1) ans = n - 2;
        else if (m == 2) ans = 0;
        else ans = m * n - 2 * (m + n) + 4;
    }

    out(ans);


    return 0;
}




//              g++ -std=c++1z




