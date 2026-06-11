#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;
    if(A+B <= 2*C) {
        cout << A*D+B*E << endl;
    } else {
        int ans = 0;
        ans += min(D,E)*2*C;
        if (D==E)
        {
            cout << ans << endl;
        }
        else if (D>E)
        {
            D -= E;
            if (A>2*C)
            {
                ans += 2*C*D;
                cout << ans << endl;
            }
            else
            {
                ans += A*D;
                cout << ans << endl;
            }
            
        }
        else
        {
            E -= D;
            if (B>2*C)
            {
                ans += 2*C*E;
                cout << ans << endl;
            }
            else
            {
                ans += B*E;
                cout << ans << endl;
            }
        }
        
    }
    return 0;
}