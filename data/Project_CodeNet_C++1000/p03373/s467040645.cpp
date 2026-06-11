#include <bits/stdc++.h>
using namespace std;
int main () {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    long long ans = LLONG_MAX;
    for (int i = 0; i <= X || i <= Y; i++) {
        long long res = i*2*C; 
        if (X > i) res += (X-i)*A;
        if (Y > i) res += (Y-i)*B;
        ans = min(ans, res);
    }
    cout << ans << endl;
}