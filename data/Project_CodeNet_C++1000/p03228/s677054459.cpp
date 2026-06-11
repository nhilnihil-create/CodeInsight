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
    ll a, b, k;
    cin >> a >> b >> k;
    for(int i = 0; i < k; i++) {
        if (a % 2 == 1)
            a -= 1;
        b += a/2;
        a /= 2;
        swap(a, b);
    }
    if (k % 2 == 1)
        swap(a, b);
    cout << a << " " << b << endl;
    return 0;
}

