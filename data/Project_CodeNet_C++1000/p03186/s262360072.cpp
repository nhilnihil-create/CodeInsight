#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll A, B, C;
    cin >> A >> B >> C;
    ll ans = 0;
    if (B <= C) {
        ans += 2*B;
        C -= B;
        ans += min(A+1, C);
    }else {
        ans = B+C;
    }
    cout << ans << endl;
    return 0;
}