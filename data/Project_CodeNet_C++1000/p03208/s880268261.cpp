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

    ll N,K;
    cin >> N >> K;
    ll h[N];
    rep(i,N) cin >> h[i];
    sort(h,h+N);
    ll out = 1000000000;
    rep(i,N-K+1){
        if(h[i+K-1]-h[i]<out) out = h[i+K-1]-h[i];
    }
    cout << out << endl;
    return 0;
}
