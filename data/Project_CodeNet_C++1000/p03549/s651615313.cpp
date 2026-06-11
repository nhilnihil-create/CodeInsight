#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {

    ll T = 1900;
    ll t = 100;
    ll N,M;
    cin >> N >> M;
    ll out = (T*M+t*(N-M))*pow(2,M);
    cout << out << endl;
    return 0;
}
