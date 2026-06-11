#include <iostream>
using namespace std;
typedef long long ll;
ll n, a[55], sei, fu, ma, mi;
int main(void){
    // Your code here!
    cin >> n;
    cout << 2 * n - 2 << endl;
    for (ll i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] > 0){
            if (a[i] >= sei){
                ma = i, sei = a[i];
            }
        } else {
            if (a[i] <= fu){
                mi = i, fu = a[i];
            }
        }
    }
    if (sei > -fu){
        for (ll i = 1; i <= n; i++){
            if (i == ma) continue;
            cout << ma << ' ' << i << endl;
        }
        for (ll i = 1; i < n; i++){
            cout << i << ' ' << i + 1 << endl;
        }
    } else {
        for (ll i = 1; i <= n; i++){
            if (i == mi) continue;
            cout << mi << ' ' << i << endl;
        }
        for (ll i = n; i > 1; i--){
            cout << i << ' ' << i - 1 << endl;
        }
    }
}
