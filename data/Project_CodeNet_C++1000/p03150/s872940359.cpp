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
    string s;
    cin >> s;
    int n = s.size();
    rep(i, n) {
        for (int j = i; j < n; ++j) {
            string t = s.substr(0, i);
            for (int k = j; k < n; ++k) {
                t += s[k];
            }
            //cout << t << endl;
            if (t == "keyence") {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
