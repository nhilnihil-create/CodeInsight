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
    string S;
    cin >> S;
    ll X = 0;
    ll Y = 753;
    ll out = Y;
    rep(i,S.length()-2){
        X = stoi(S.substr(i,3));
        out = min(out,abs(X-Y));
    }
    cout << out << endl;
    return 0;
}
