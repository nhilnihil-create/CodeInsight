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
    ll x, y;
    cin >> x >> y;
    if (x % y == 0) {
        cout << -1 << endl;
    } else {
        vector<ll> cand = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
        for(auto val: cand) {
            if ((x*val) % y != 0) {
                cout << (x*val) << endl;
                return 0;
            }
        }
        return 0;
    }
    return 0;
}
