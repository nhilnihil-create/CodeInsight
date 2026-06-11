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

    ll N;
    cin >> N;
    ll sum = 0;
    ll mx = 0;
    rep(i,N){
        ll L;
        cin >> L;
        sum += L;
        if(L>mx) mx = L;
    }
    string out = "Yes";
    if(mx>=sum-mx) out = "No";
    cout << out << endl;
    return 0;
}
