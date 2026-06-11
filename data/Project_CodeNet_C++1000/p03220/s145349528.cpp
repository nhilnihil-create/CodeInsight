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
    ll N,T,A;
    cin >> N >> T >> A;
    ll H[N];
    rep(i,N) cin >> H[i];
    ll out = 0;
    double def = 100000;
    rep(i,N){
        double tem = T-H[i]*0.006;
        if(abs(tem-A)<def){
            out = i+1;
            def = abs(tem-A);
        }
    }
    cout << out << endl;
    return 0;
}

