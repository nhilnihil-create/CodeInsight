#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <cstring>
#include <queue>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <bitset>

using namespace std;

using ll = long long;
using Vec = vector<ll>;
using P = pair<ll, ll>;
using VecP = vector<P>;
#define rep(i, n) for(ll i=0;i<(n);i++)
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))

//static const ll MOD = 1000000007;
//static const ll INF = 100000000;
//#define PI 3.14159265359


int main() {
    // input
    ll N;
    cin >> N;
    vector<int> D(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> D[i];
    }

    //process
    sort(D.begin(), D.end());

    ll ans = 24;
    ll r = 0, l = 0;
    rep(i, N) {
        if (i % 2 == 0) {
            ans = min(ans, abs(l - D[i]));
            ans = min(ans, abs(r - D[i]));
            r = D[i];
        } else {
            ans = min(ans, abs(l - (24 - D[i])));
            ans = min(ans, abs(r - (24 - D[i])));
            l = 24 - D[i];
        }
    }

    cout << ans << endl;
    return 0;
}

