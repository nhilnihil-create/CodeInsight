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

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {

    ll N,K;
    cin >> N >> K;
    ll x[N];
    rep(i,N) cin >> x[i];
    ll out = 0;
    rep(i,N-K+1){
        ll tmp = min(abs(x[i]) + abs(x[i]-x[i+K-1]),abs(x[i+K-1]) + abs(x[i]-x[i+K-1]));
        if(i==0) out = tmp;
        else out = min(out,tmp);
    }
    cout << out << endl;
    return 0;
}
