#include <bits/stdc++.h>
using namespace std;

int main(void){
    int d, n, x, ans = 0, cnt = 1;
    cin >> d >> n;
    x = pow(100, d);
    if (n == 100) n++;
    while (cnt <= n){
        ans += x;
        cnt++;
    }
    cout << ans << endl;
    return 0;
}