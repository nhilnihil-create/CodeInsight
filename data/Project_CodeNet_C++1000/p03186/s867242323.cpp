#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c;
    int ans = 0;
    cin >> a >> b >> c;

    if (c >= b) {
        if (a+b >= c) {
            ans = b + c;
        }
        else {
            ans = a + 2*b + 1;
        }
    }
    else {
        ans = b + c;
    }
    cout << ans << endl;
   
    return 0;
}