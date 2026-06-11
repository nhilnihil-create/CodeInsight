#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int ans = numeric_limits<int>::max();
    for(int i=0; i<=max(X, Y); ++i) {
        ans = min(ans, 2*C*i + A*max(0, X-i) + B*max(0, Y-i));
    }

    cout << ans << endl;
    return 0;
}
