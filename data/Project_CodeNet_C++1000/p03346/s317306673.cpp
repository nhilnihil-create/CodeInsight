#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();

// find consecutive LIS
int main() {
    int n, val;
    cin >> n;

    vector<int> pos(n+1, INT_MAX);
    for(int i = 0; i < n; i++) {
        cin >> val;
        pos[val] = i;
    }
    int cnt = 0, ans = 1;
    for(int i = 1; i <= n; i++) {
        if (pos[i] > pos[i-1]) {
            cnt += 1;
            ans = max(ans, cnt);
        } else {
            cnt = 1;
        }
    }
    cout << n - ans << endl;
    return 0;
}

