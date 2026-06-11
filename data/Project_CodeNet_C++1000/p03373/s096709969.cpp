#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
int A, B, C, X, Y;
cin >> A >> B >> C >> X >> Y;

int ans = 0;
if( 2*C <= A && 2*C <= B){
    ans = 2*C*max(X, Y);
}else if( A+B <= 2*C ){
    ans = A*X + B*Y;
}else if( A+B > 2*C){
    ans = min(2*C*max(X, Y), min(X, Y)*2*C + A*( X-min(X, Y)) + B*( Y-min(X, Y)));
}
cout << ans << endl;

}
