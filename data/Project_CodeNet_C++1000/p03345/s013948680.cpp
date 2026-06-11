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
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    if (k % 2 == 0)
        cout << a - b << endl;
    else
        cout << b - a << endl;
    return 0;
}

