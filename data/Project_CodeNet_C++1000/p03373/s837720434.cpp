#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, C, X, Y;

    cin >> A >> B >> C >> X >> Y;
    int ans = 0;
    
    if (C * 2 < A + B) {
        int i = min(X,Y);
        ans += i*C*2;
        X -= i;
        Y -= i;
    }
    if (C * 2 < A) A = C*2;
    if (C * 2 < B) B = C*2;
    ans += A * X + B * Y;
    cout << ans << endl;
}