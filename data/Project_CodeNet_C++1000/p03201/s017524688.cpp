#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();

int main() {
    int n, val, ans = 0;
    cin >> n;
    map<int, int> cnt;
    for(int i =0; i < n; i++) {
        cin >> val;
        cnt[val] += 1;
    }
    int m = cnt.rbegin()->first;
    int target = 1;
    while (target <= m) {
        target *= 2;
    }

    while (target > 1) {
        int half = target/2;
        auto it = cnt.lower_bound(half);
        if (it->first == half) {
            ans += it->second / 2;
            it->second %= 2;
            ++it;
        }
        //cout << "target: " <<target << endl;
        while (it != cnt.end()) {
            if (cnt.count(target - it->first) > 0) {
                int valid = min(it->second, cnt[target - it->first]);
                ans += valid;
                it->second -= valid;
                cnt[target - it->first] -= valid;
                //cout << "pair " << it->first << ", " << target-it->first << endl;
            }
            // cout << it->first << endl;
            ++it;
        }
        cnt.erase(cnt.lower_bound(half), cnt.end());
        target /= 2;
    }
    cout << ans << endl;
    return 0;
}


