#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
    int minnum = 9, lastadd, ans = 0;
    vector<int> ordertime(5);
    rep(i, 5) {
        cin >> ordertime[i];
        if (minnum >= ordertime[i]%10 && ordertime[i]%10 != 0) {
            lastadd = i;
            minnum = ordertime[i] % 10;
        }
    }
    rep(i, 5) { 
        if (i != lastadd){
            ans += (ordertime[i] + (10 - ordertime[i]%10) % 10);
        }
    }
    ans += ordertime[lastadd];

    cout << ans << endl;
}