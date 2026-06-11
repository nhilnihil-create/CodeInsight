#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i < n + 1; i++)
#define PI 3.14159265359
#define EPS 0.0000000001
#define MOD 1000000007
//cout << std::fixed << std::setprecision(15) << y << endl;


int main(){
    ll c[3][3];
    rep(i, 3){
        rep(j, 3){
            cin >> c[i][j];
        }
    }

    bool a12 = (c[1][0] - c[0][0] == c[1][1] - c[0][1] && c[1][1] - c[0][1] == c[1][2] - c[0][2]);
    bool a23 = (c[2][0] - c[1][0] == c[2][1] - c[1][1] && c[2][1] - c[1][1] == c[2][2] - c[1][2]);
    bool b12 = (c[0][1] - c[0][0] == c[1][1] - c[1][0] && c[1][1] - c[1][0] == c[2][1] - c[2][0]);
    bool b23 = (c[0][2] - c[0][1] == c[1][2] - c[1][1] && c[1][2] - c[1][1] == c[2][2] - c[2][1]);

    if(a12 && a23 && b12 && b23){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}