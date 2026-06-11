#include <bits/stdc++.h>
using namespace std;
int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    
    int ans;

    if (A + B > 2 * C){
        if (A > 2 * C && B > 2 * C){
            ans = 2 * C * max(X, Y);
        }
        else{
            if (X < Y){
                if (B > 2 * C){
                    ans = 2 * C * max(X, Y);
                }
                else{
                    ans = 2 * C * X + B * (Y - X);
                }
            }
            else{
                if (A > 2 * C){
                    ans = 2 * C * max(X, Y);
                }
                else{
                     ans = 2 * C * Y + A * (X - Y);
                }
            }
        }
    }
    else{
        ans = A * X + B * Y;
    }
    
    cout << ans << endl;
}
