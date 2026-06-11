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
    int n, h, w, r, c;
    cin >> n >> h >> w;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> r >> c;
        if (r >= h && c >= w)
            ans += 1;
    }
    cout << ans << endl;
    return 0;
}
