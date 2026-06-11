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
const ll LINF = 1001002003004005006ll;

int main() {
    int n;
    cin >> n;
    vector<int> num(55556, 0);
    for (int i = 2; i * i <= 55555; ++i) {
        if (num[i] == 0) {
            int idx = i;
            while(1) {
                if (idx >= 55555) break;
                num[idx]++;
                idx += i;
            }
        }
    }
    vector<int> ans;
    int cnt = 0;
    rep(i, 55556) {
        if (num[i] == 0 && i % 10 == 1 && i != 1) {
            ans.push_back(i); 
            ++cnt;
        }
        if (cnt == n) break;
    }
    rep(i, (int)(ans.size())) {
        if (i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
