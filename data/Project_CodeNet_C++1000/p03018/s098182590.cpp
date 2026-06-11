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

string s;
llong ans;

int main() {
    cin >> s;

    llong cnt = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (i > 0 && s[i] == 'C' && s[i - 1] == 'B') {
            cnt++;
            i--;
        }
        else if (s[i] == 'A') {
            ans += cnt;
        }
        else {
            cnt = 0;
        }
    }

    cout << ans << endl;

    return 0;
}
