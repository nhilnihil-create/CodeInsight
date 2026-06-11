#include <bits/stdc++.h>

using namespace std;

long long func (long long x) {
    long long cnt1 = (x + 1) / 2;
    long long ans = cnt1 % 2;
    if ( x % 2 == 0 )
        ans ^= x;
    return ans;
}

int main (void) {
    long long A, B;
    cin >> A >> B;
    long long ans = func(A-1) ^ func(B);
    cout << ans << endl;
    return 0;
}
