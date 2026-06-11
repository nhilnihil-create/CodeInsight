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
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)
const ll LINF = 1001002003004005006ll;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    if (abs(a - b) % 2 == 0) {
        cout << "Alice" << endl;
    }
    else { 
        cout << "Borys" << endl;
    }
    return 0;
}
