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

    ll N,H;
    cin >> N >> H;
    ll a[N];
    ll b[N];
    ll aMax = 0;
    rep(i,N){
        cin >> a[i] >> b[i];
        aMax = max(aMax,a[i]);
    }
    sort(b,b+N);
    ll out = 0;
    ll sum = 0;
    rep(i,N){
        if(b[N-1-i]>aMax){
            sum += b[N-1-i];
            out++;
            if(sum>=H) break;
        }else break;
    }
    while(sum<H){
        sum += aMax;
        out++;
    }
    cout << out << endl;
    return 0;
}
