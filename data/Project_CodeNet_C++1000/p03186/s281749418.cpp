#include <iostream>

using namespace std;

int main() {
    int a , b , c;
    cin >> a >> b >> c;
    if(b >= c) {
        cout << b + c;
    }
    else {
        int ans = b;
        c -= b;
        c --;
        ans += b + 1;
        ans += min(a , c);
        cout << ans;
    }

    return 0;
}
