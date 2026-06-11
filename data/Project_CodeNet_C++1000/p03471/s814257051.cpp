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
#include <cstring>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int n, y;
    cin >> n >> y;
    rep(i, n+1) rep(j, n-i+1) {
        if (10000*i + 5000*j + 1000*(n-i-j) == y) {
            cout << i << " " << j << " " << n-i-j << endl;
            return 0;
        }
    }
    cout << "-1 -1 -1" << endl;
    return 0;
}
