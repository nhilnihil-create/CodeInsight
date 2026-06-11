#include <bits/stdc++.h>
 
using namespace std;
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i< (int) n; i++)
#define PI  3.14159265358979323846264338327950
 
int main () {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    long long ans = 100000000000;
    for(int i =0;  i < 100001; i ++){
        int a = max(0,X-i);
        int b = max(0,Y-i);

        ans = min(ans,(long long ) C*2*i+A*a+B*b );
    }

    cout << ans << endl;

}
