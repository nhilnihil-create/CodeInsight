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

    ll N,M;
    cin >> N >> M;
    ll A[M];
    rep(i,M) A[i] = 0;
    rep(i,N){
        ll K;
        cin >> K;
        rep(j,K){
            ll a;
            cin >> a;
            A[a-1]++;
        }
    }
    ll out = 0;
    rep(i,M){
        if(A[i]==N) out++;
    }
    cout << out << endl;
    return 0;
}
