#include <bits/stdc++.h>

using namespace std;

int main(void) {

    int A, B; double T;
    cin >> A >> B >> T;
    T += 0.5;

    int ans = 0;
    double t = A;
    while(t <= T) {
        t += A;
        ans += B;
    }

    cout << ans << endl;
    return 0;
}