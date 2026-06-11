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

    string S;
    cin >> S;
    string out = "TBD";
    ll Y = stoi(S.substr(0,4));
    ll M = stoi(S.substr(5,2));
    if(Y<2019) out = "Heisei";
    else if(Y==2019){
        if(M<=4) out = "Heisei";
        }
    cout << out << endl;
    return 0;
}
