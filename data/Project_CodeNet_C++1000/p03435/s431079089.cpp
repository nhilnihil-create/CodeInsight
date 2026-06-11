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
    ll C[3][3];
    rep(i,3){
        rep(j,3) cin >> C[i][j];
    }
    string out = "Yes";
    rep(i,3){
        rep(j,3){
            if(C[i][j]-C[i][0]==C[0][j]-C[0][0]||C[i][j]-C[0][j]==C[i][0]-C[0][0]);
            else{
                out = "No";
                break;
            }
        }
    }
    cout << out << endl;
    return 0;
}

