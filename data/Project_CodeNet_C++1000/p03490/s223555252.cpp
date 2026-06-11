#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <utility>
#include <algorithm>
#include <functional>
#include <deque>
#define INF 1e9
#define MAX_L 8001

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int main() {
    string s;
    int x, y;
    cin >> s >> x >> y;
    int len = (int)s.size();
    
    int count = 0;
    int is_x = true;
    vector<int> x_list, y_list;
    for (int i = 0; i < len; ++i) {
        char c = s[i];
        if (c == 'F') {
            count++;
        } else {
            if (is_x) {
                x_list.push_back(count);
            } else {
                y_list.push_back(count);
            }
            count = 0;
            is_x = !is_x;
        }
    }
    if (is_x) {
        x_list.push_back(count);
    } else {
        y_list.push_back(count);
    }
    
    int x_size = (int)x_list.size();
    int y_size = (int)y_list.size();
    bool x_dp[2][2 * MAX_L];
    bool y_dp[2][2 * MAX_L];
    for (int i = 0; i < 2; ++i) {
        fill(x_dp[i], x_dp[i] + 2 * MAX_L, false);
        fill(y_dp[i], y_dp[i] + 2 * MAX_L, false);
    }
    x_dp[0][MAX_L + x_list[0]] = true;
    y_dp[1][MAX_L] = true;
    
    for (int i = 1; i < x_size; ++i) {
        fill(x_dp[i % 2], x_dp[i % 2] + 2 * MAX_L, false);
        for (int j = 0; j < 2 * MAX_L; ++j) {
            if (x_dp[(i + 1) % 2][j]) {
                x_dp[i % 2][j + x_list[i]] = true;
                x_dp[i % 2][j - x_list[i]] = true;
            }
        }
    }
    for (int i = 0; i < y_size; ++i) {
        fill(y_dp[i % 2], y_dp[i % 2] + 2 * MAX_L, false);
        for (int j = 0; j < 2 * MAX_L; ++j) {
            if (y_dp[(i + 1) % 2][j]) {
                y_dp[i % 2][j + y_list[i]] = true;
                y_dp[i % 2][j - y_list[i]] = true;
            }
        }
    }
    
    if (x_dp[(x_size + 1) % 2][MAX_L + x] && y_dp[(y_size + 1) % 2][MAX_L + y]) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    
    return 0;
}
