#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
#define endl "\n"
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

int main() {
    ll n, x;
    cin >> n >> x;
    vector<ll> arr(n, 0);
    for(auto& val: arr)
        cin >> val;
    sort(arr.begin(), arr.end());
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if (x >= arr[i]) {
            x -= arr[i];
            ans += 1;
        }
    }
    if (ans == n && x != 0) {
        ans -= 1;
    }
    cout << ans << endl;
    return 0;
}
