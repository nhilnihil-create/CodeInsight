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
    int n;
    cin >> n;
    vector<ll> arr(n, 0);
    for(auto& val: arr)
        cin >> val;
    if (arr[0] != 0) {
        cout << -1 << endl;
    } else {
        for(int i = 1; i < n; i++) {
            if (arr[i] - arr[i-1] > 1) {
                cout << -1 << endl;
                return 0;
            }
        }
        ll ans = 0;
        for(int i = n-1; i >= 0; i--) {
            if (i != n-1 && arr[i]+1 == arr[i+1])
                continue;
            ans += arr[i];
        }
        cout << ans << endl;
    }
    return 0;
}


