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
    ll K, A, B;
    cin >> K >> A >> B;

    // process
    ll biscuit = 1;

    if (A + 2 >= B) {
        biscuit += K;
    } else {
        biscuit = A;
        K -= A - 1;
        if (K % 2 == 0) {
            biscuit += (B - A) * K / 2;
        } else if (K % 2 == 1 && K > 2) {
            biscuit += (B - A) * (K - 1) / 2;
            biscuit++;
        } else {
            biscuit++;
        }
    }

    cout << biscuit << endl;

    return 0;
}

