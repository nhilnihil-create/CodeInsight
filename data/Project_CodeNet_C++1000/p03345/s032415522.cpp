#include <iostream>
typedef long long ll;
using namespace std;

int main() {
    ll A, B, C, K, ans;
    cin >> A >> B >> C >> K;

    ans = A-B;
    if(ans > 10e18) {
        cout << "Unfair" << endl;
        exit(0);
    }
    if(K%2 != 0) ans = -ans;    // odd case
    cout << ans << endl;
}