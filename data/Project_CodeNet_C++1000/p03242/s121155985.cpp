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
    string n;
    cin >> n;
    rep(i,3){
        if(n[i]=='1') n[i] = '9';
        else n[i] = '1';
    }
    cout << n << endl;
    return 0;
}

