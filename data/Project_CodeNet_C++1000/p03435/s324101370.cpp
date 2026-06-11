#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    vector<vector<int>> c(3, vector<int>(3, 0));
    rep(i, 3) rep(j, 3) cin >> c[i][j];
    int min_num1 = min({c[0][0], c[0][1], c[0][2]});
    int min_num2 = min({c[1][0], c[1][1], c[1][2]});
    int min_num3 = min({c[2][0], c[2][1], c[2][2]});
    bool ok = true;
    if ( c[0][0] - min_num1 != c[1][0] - min_num2 || c[1][0] - min_num2 != c[2][0] - min_num3 ) {
        ok = false;
    }
    if ( c[0][1] - min_num1 != c[1][1] - min_num2 || c[1][1] - min_num2 != c[2][1] - min_num3 ) {
        ok = false;
    }
    if ( c[0][2] - min_num1 != c[1][2] - min_num2 || c[1][2] - min_num2 != c[2][2] - min_num3 ) {
        ok = false;
    }
    
    if ( !ok ) cout << "No" << endl;
    else       cout << "Yes" << endl;

    return 0;
}
