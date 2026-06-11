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

    ll R,G,B,N;
    cin >> R >> G >> B >> N;
    ll r = N/R;
    ll g = N/G;
    ll out = 0;
    rep(i,r+1){
        rep(j,g+1){
            if((N-i*R-j*G)%B==0&&(N-i*R-j*G)/B>=0){
                out++;
            }
        }
    }
    cout << out << endl;
    return 0;
}
