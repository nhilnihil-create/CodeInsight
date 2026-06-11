#include <bits/stdc++.h>
using namespace std;


int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
  
    int64_t ans = 100000*10000;
  
    for (int i = 0; i <= max(X, Y)*2; i += 2) {
        int64_t ans2 = i*C + max(0,X-i/2)*A + max(0,Y-i/2)*B;
        ans = min(ans, ans2);
    }
    cout << ans << endl;
}