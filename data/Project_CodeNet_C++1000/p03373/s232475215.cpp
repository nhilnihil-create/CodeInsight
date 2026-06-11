#include <bits/stdc++.h>
using namespace std;

int main() {
    int A,B,C;
    long long X,Y;
    cin >> A >> B >> C >> X >> Y;
    long long ans1=0;
    long long ans2=0;
    long long ans=0;

    if((A+B) > 2*C){
        ans1 = min(X,Y)*2*C + max(0LL,X-min(X,Y))*A +max(0LL,Y-min(X,Y))*B;
        ans2 = max(X,Y)*2*C;
        ans = min(ans1,ans2);
    } else {
        ans = A*X + B*Y;
    }
    cout << ans << endl;
}