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
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int ans = 0;
    rep(i, n) {
        while(1) {
            if ( a[i] % 2 == 1 ) break;
            a[i] /= 2;
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
