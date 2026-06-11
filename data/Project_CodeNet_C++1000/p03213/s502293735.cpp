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
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 2; i <= n; ++i) {
        int tmp = i;
        for (int j = 2; j * j <= i; ++j) {
            while(1) {
                if (tmp % j != 0) break;
                ++mp[j];
                tmp /= j;
            }
        }
        //cout << i << " " << tmp << endl;
        if (tmp!=1) ++mp[tmp];
    }
    //for (auto p : mp) {
    //    cout << p.first << " " << p.second << endl;
    //}
    vector<int> dp(76, 0);
    dp[1] = 1;
    for (int i = 1; i <= 100; ++i) {
        if (mp[i]!=0) {
            for (int j = 75; j >= 1; --j) {
                for (int x = 1; x <= mp[i]; ++x) {
                    if (j * (x+1) <= 75) {
                        dp[j*(x+1)] += dp[j];
                    } 
                }
            }
        }
    }
    cout << dp[75] << endl;
    return 0;
}