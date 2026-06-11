#include <iostream>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    int ans = 0;
    rep(i, 2) {
        if (A >= B) {
            ans += A;
            A--;
        }else {
            ans += B;
            B--;
        }
    }
    cout << ans << endl;
    return 0;
}