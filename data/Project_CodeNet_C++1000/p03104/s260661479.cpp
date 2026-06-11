#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t A,B;
    cin >> A >> B;
    
    int64_t num;
    int64_t ans = 0;
    if ( A % 2 == 0 ){
        if ( B % 2 == 0 ){
            num = B - A;
            ans = num/2;
            ans = ans%2;
            ans = ans^B;
        } else {
            num = B - A + 1;
            ans = num/2;
            ans = ans%2;
        }
    } else {
        if ( B % 2 == 0 ){
            num = B - A - 1;
            ans = num/2;
            ans = ans%2;
            ans = ans^A;
            ans = ans^B;
        } else {
            num = B - A;
            ans = num/2;
            ans = ans%2;
            ans = ans^A;
        }
    }
    
    cout << ans << endl;
    return 0;
}
