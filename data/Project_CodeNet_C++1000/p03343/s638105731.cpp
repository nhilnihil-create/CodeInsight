#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <cassert>
#include <random>
#include <tuple>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
typedef long long ll;
typedef pair<int, int> P;


const int INF = 1001001001;

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int ans = INF;

    rep(i, n) {
        stack<vector<int> > s;

        vector<int> tmp(0);
        rep(j, n) {
            if (a[j] < a[i]) {
                if (tmp.size() >= k) s.push(tmp);
                tmp.clear();
            } else {
                tmp.push_back(a[j]);
            }
        }
        if (tmp.size() >= k) s.push(tmp);

        vector<int> xy;
        while (!s.empty()) {
            vector<int> box = s.top(); s.pop();
            sort(box.begin(), box.end());
            rep(j, box.size()-k+1) {
                xy.push_back(box[j]);
            }
        }

        if (xy.size() < q) continue;
        sort(xy.begin(), xy.end());
        ans = min(ans, xy[q-1] - a[i]);
    }
    
    cout << ans << endl;

    return 0;

}
