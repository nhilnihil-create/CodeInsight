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

    ll N;
    cin >> N;
    ll btc = 380000;
    double out = 0;
    double x = 0;
    string u = "";
    rep(i,N){
        cin >> x >> u;
        if(u=="JPY") out += x;
        else out += x*btc;
    }
    cout << fixed << setprecision(6) << out << endl;
    return 0;
}
