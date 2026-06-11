#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
#include <deque>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;

#define INF 1e18
#define int long long

bool f = 0;

void dfs(string s, int i) {
    if(s == "AKIHABARA") {
        f = 1;
        return;
    }
    if(i > s.size()) return;
    dfs(s, i + 1);
    s.insert(s.begin() + i, 'A');
    dfs(s, i + 2);
}

signed main () {
    string s; cin >> s;
    if(s.size() > 9) {
        cout << "NO" << endl;
        return 0;
    }
    dfs(s, 0);
    if(!f) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}
