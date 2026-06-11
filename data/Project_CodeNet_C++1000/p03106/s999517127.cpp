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

    ll A,B,K;
    cin >> A >> B >> K;
    ll C[100];
    rep(i,100) C[i] = 0;
    ll cnt = 0;
    rep(i,A){
        if(A%(i+1)==0&&B%(i+1)==0){
            C[cnt] = i+1;
            cnt++;
        }
    }
    cout << C[cnt-K] << endl;
    return 0;
}
