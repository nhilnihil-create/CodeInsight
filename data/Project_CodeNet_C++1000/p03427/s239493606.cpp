#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    ll n;
    cin >> n;
    int ans = 0, x;
    bool flag = false;
    while (n != 0){
        x = n % 10;
        n /= 10;
        if (x != 9 && n != 0) flag = true;
        if (n > 0) ans += 9;
        else ans += x;
    }
    cout << ans - flag << endl;
    return 0;
}