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
#include <queue>

using namespace std;
typedef long long ll;
using Graph = vector<vector<ll>>;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {
    ll D;
    cin >> D;
    string out = "Christmas";
    if(D==24) out = "Christmas Eve";
    else if(D==23) out = "Christmas Eve Eve";
    else if(D==22) out = "Christmas Eve Eve Eve";
    cout << out << endl;
    return 0;
}
