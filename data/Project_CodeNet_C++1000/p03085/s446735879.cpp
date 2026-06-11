#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {

    string b;
    cin >> b;
    string out = "";
    if(b=="A") out = "T";
    else if(b=="T") out = "A";
    else if(b=="C") out = "G";
    else if(b=="G") out = "C";
    cout << out << endl;
    return 0;
}
