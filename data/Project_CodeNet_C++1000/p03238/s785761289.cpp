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
    ll N;
    cin >> N;
    if(N==1) cout << "Hello World" << endl;
    else{
        ll A,B;
        cin >> A >> B;
        cout << A+B << endl;
    }
    return 0;
}

