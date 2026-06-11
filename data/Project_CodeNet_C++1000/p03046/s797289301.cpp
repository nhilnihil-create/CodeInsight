#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define debug(x) cout << #x << " = " << x << endl
#define fori(i, ini, lim) for(int i = int(ini); i < int(lim); i++)
#define ford(i, ini, lim) for(int i = int(ini); i >= int(lim); i--)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

void solve() {
    int m, k;
    cin >> m >> k;
    if (k >= ((1 << m))) {
        cout << "-1" << endl;
        return;
    }
    if (m == 1) {
        if (k == 1) cout << "-1" << endl;
        else cout << "0 0 1 1" << endl;
    }
    else {
        fori (i, 0, (1 << m)) {
            if (i != k) cout << i << " ";
        }
        cout << k << " ";
        ford (i, (1 << m) - 1, 0) {
            if (i != k) cout << i << " ";
        }
        cout << k << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

