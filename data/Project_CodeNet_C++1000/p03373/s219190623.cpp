#include <bits/stdc++.h>
using namespace std;
 
int main () {
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    
    if( 2*C > A+B) {
        cout << A * X + B * Y;
    } else {
        int long_num = max (X, Y);
        int shrt_num = min (X, Y);
        if (X > Y) cout << min ( long_num * C * 2, shrt_num * 2 * C + (long_num - shrt_num) * A); 
        if (Y > X) cout << min ( long_num * C * 2, shrt_num * 2 * C + (long_num - shrt_num) * B);
        if (Y == X) cout << long_num * C * 2;
    }
    cout << endl;
    return 0;
}