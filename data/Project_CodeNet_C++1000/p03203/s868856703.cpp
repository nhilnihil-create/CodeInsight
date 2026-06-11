#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <list>
#include <deque>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
#define dump(a) cout << (a) << endl;
typedef long long ll;
ll mod = 1e9+7;

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> s(h+1, 1e9);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x-y+1 > 0) s[x-y+1] = min(s[x-y+1], y);
    }
    int res = h;
    for (int i = 2; i <= h; i++) {
        if (s[i] < s[i-1]) {
            res = min(res, i+s[i]-2);
        }
    }
    dump(res);
    return 0;  
}