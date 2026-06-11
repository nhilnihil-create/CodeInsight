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

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    if (abs(a-b) % 2 == 1) {
        cout << "Borys" << endl;
    }
    else {
        cout << "Alice" << endl;
    }
    return 0;
}