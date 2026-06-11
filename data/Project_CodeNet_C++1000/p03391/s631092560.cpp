#include <iostream>
using namespace std;
typedef long long ll;
ll sma, sum, n;
bool ans = true;
int main(void){
    // Your code here!
    sma = 1000000000000;
    cin >> n;
    for (ll i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        if (a != b) ans = false;
        sum += a;
        if (a > b) sma = min(sma, b);
    }
    if (ans) cout << 0 << endl;
    else cout << sum - sma << endl;
}
