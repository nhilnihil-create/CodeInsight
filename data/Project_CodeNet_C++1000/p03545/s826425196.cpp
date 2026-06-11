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
    vector<int> num(4);
    string in_num;
    cin >> in_num;
    rep(i, 4) num[i] = in_num[i] - '0';
    //cout << "test" << endl;
    rep(i, 1<<3) {
        int sum = num[0];
        string ans = "";
        ans += in_num[0];
        rep(j, 3) {
            //cout << in_num[j+1] << endl;
            if (i>>j & 1) {
                sum += num[j+1];
                ans += '+';
                ans += in_num[j+1];
            }
            else {
                sum -= num[j+1];
                ans += '-';
                ans += in_num[j+1];
            }
            //cout << ans << endl;
        }
        //cout << sum << endl;
        if (sum == 7) {
            cout << ans + "=7" << endl;
            return 0;
        }
    }
    return 0;
}