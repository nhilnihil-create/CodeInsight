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

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int x;
    cin >> x;
    vector<bool> flg(x+1, false);
    flg[1] = true;
    for ( int i = 2; i * i <= x; ++i ) {
        int num = i;
        while(1) {
            if ( num > x ) break;
            flg[num] = true;
            num *= i;
        }
    }
    int ans = 0;
    rep(i, x+1) {
        if ( flg[i] ) {
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}
