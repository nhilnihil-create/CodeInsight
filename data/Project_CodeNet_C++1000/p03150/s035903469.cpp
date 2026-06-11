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
using Graph = vector<vector<ll>>;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {
    string S;
    cin >> S;
    string out = "NO";
    rep(i,8){
        string s = S;
        s.erase(i,S.length()-7);
        if(s=="keyence"){
            out = "YES";
            break;
        }
    }
    cout << out << endl;
    return 0;
}

