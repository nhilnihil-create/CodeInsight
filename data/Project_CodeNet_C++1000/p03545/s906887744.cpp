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
    string s;
    cin >> s;
    vector<int> num(4);
    rep(i, 4) {
        num[i] = s[i] - '0';
    }
    rep(i, 1<<3) {
        int sum = num[0];
        string ans = "";
        ans += (char)(num[0] + '0');
        rep(j, 3) {
            if ((i>>j) & 1) {
                sum += num[j+1];
                ans += '+';
                ans += (char)(num[j+1] + '0');
            }
            else {
                sum -= num[j+1];
                ans += '-';
                ans += (char)(num[j+1] + '0');
            }
        }
        if (sum == 7) {
            for (auto aa: ans) {
                cout << aa;
            }
            cout << "=7" << endl;
            return 0;
        }
    }
    return 0;
}
