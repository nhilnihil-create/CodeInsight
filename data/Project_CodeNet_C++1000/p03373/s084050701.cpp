#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int ans=1000000000;
    
    for (int i=0; i<=100000; i++){
        ans=min(2*C*i+max(0, X-i)*A+max(0, Y-i)*B, ans);
    }
    cout << ans << endl;
}
