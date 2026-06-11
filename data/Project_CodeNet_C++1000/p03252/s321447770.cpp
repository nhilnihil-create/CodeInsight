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
    string s,t;
    cin >> s >> t;
    vector<int> start(26, -1);
    vector<int> goal(26, -1);
    rep(i, s.size()) {
        int a = s[i] - 'a';
        int b = t[i] - 'a';

        if (start[a] != -1 || goal[b] != -1) {
            if (start[a] != b || goal[b] != a) {
                cout << "No" << endl;
                return 0;
            }
        }
        else {
            start[a] = b;
            goal[b] = a;
        }
    }
    cout << "Yes" << endl;
    return 0;
}