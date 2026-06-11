#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);
int cnt(int n) {
    int ans = 0;
    while (n > 0) {
        ans += n % 10;
        n/=10;
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    int ans = INT_MAX;
    for(int i = 1; i <= n-i; i++) {
        ans = min(ans, cnt(i)+cnt(n-i));
    }
    cout << ans << endl;
    return 0;
}


