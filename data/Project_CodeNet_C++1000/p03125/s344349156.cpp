#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
    int a, b, ans;
    cin >> a >> b;
    if(b % a) ans = b - a;
    else ans = a + b;
    cout << ans << endl;
}