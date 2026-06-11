#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

int main() {
    int n, a, b;
    cin >> n;
    vector<vector<int>> red;
    vector<vector<int>> blue;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        red.push_back({a, b});
    }
    sort(red.begin(), red.end());
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        blue.push_back({a, b});
    }
    sort(blue.begin(), blue.end());
    int r_idx = 0, ans = 0;
    multiset<int> cand;
    for(int i = 0; i < n; i++) {
        while(r_idx < n && red[r_idx][0] < blue[i][0]) {
            cand.insert(red[r_idx++][1]);
        }
        if (cand.size() > 0) {
            auto it = cand.lower_bound(blue[i][1]);
            if (it != cand.begin()) {
                ans += 1;
                cand.erase(prev(it));
            }
        }
    }
    cout << ans << endl;
    return 0;
}

