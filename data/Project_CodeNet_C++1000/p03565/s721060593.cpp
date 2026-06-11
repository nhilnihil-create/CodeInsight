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

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    for (int i = n - m; i >= 0; --i) {
        bool ok = true;
        rep(j, m) {
            if (s[i+j] != t[j] && s[i+j] != '?') {
                ok = false;
                break;
            }
        }
        if (ok) {
            rep(j, m) {
                s[i+j] = t[j];
            }
            rep(j, n) {
                if (s[j] == '?') cout << 'a';
                else             cout << s[j]; 
            }
            cout << endl;
            return 0;
        }
    }
    cout << "UNRESTORABLE" << endl;
    return 0;
}
