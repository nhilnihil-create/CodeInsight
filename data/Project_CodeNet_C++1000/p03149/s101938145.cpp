#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
using llong = long long;

llong n;
llong cnt[10];

int main() {
    for (int i = 0; i < 4; i++) {
        cin >> n;
        cnt[n] = 1;
    }

    if (cnt[1] && cnt[9] && cnt[7] && cnt[4]) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
