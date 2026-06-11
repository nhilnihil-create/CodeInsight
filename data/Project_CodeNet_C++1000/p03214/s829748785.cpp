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
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(auto& val: arr)
        cin >> val;
    int S = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;
    int gap = 1e5;
    for(int i = 0; i < n; i++) {
        if (abs(arr[i]*n-S) < gap) {
            gap = abs(arr[i]*n-S);
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}
