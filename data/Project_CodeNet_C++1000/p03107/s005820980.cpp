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
    ll zero = 0;
    ll one = 0;
    rep(i,S.length()){
        if(S[i]=='0') zero++;
        else one++;
    }
    cout << min(zero,one)*2 << endl;
    return 0;
}
