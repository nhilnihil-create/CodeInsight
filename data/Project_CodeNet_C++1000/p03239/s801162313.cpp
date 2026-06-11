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
    ll N,T;
    cin >> N >> T;
    ll out = 10000;
    rep(i,N){
      ll c,t;
      cin >> c >> t;
      if(t<=T) out = min(out,c);
    }
    if(out!=10000) cout << out << endl;
    else cout << "TLE" << endl;
    return 0;
}

