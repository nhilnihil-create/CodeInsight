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

    ll K,A,B;
    cin >> K >> A >> B;
    ll out = 1;
    if(B-A<2) out += K;
    else{
        if(K-A<1) out += K;
        else{
            ll k = K-A+1;
            ll i = k/2;
            out += A-1+(B-A)*i;
            if(k%2==1) out++;
        }
    }
    cout << out << endl;
    return 0;
}
