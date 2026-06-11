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
    ll X[N];
    ll x[N];
    rep(i,N){
        cin >> X[i];
        x[i] = X[i];
    }
    sort(x,x+N);
    ll out = 0;
    rep(i,N){
        if(X[i]<=x[N/2-1]) out = x[N/2];
        else out = x[N/2-1];
        cout << out << endl;
    }
    return 0;
}
