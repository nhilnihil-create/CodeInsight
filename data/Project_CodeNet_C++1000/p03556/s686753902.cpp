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
    ll l = 0, r = n;
    while (l < r) {
        ll mid = l + (r-l)/2;
        if (mid*mid > n)
            r = mid-1;
        else
        {
            l = mid;
        }
        if (l + 1 == r) {
            if (r*r <= n) cout << r*r << endl;
            else cout << l*l << endl;
            return 0;
        }
        
    }
    cout << l*l << endl;
    return 0;
}
