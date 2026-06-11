#include<bits/stdc++.h>
using namespace std;

int main() {
    long long k, a, b; cin >> k >> a >> b;
    k++;
    if(a + 2 > b || a + 2 > k) cout << k << endl;
    else  {
        long long res = 0;
        k -= a+2;
        res = b;
        res += k/2 * (b - a);
        res += k % 2;
        cout << res << endl;
    }
    return 0;
}
