#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <stdio.h>
#include <vector>

using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {

    ll A,B,C;
    cin >> A >> B >> C;
    ll out = B/A;
    if(out>C) out=C;
    cout << out << endl;
    return 0;
}
