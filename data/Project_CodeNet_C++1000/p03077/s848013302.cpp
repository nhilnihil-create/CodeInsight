#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    ll a[5] = {}, n;
    cin >> n;
    for (int i = 0; i < 5; i++) cin >> a[i];
    cout << (n - 1) / min({a[0], a[1], a[2], a[3], a[4]}) + 5;
    return 0;
    int T;
    cin >> T;
    for (int U = 1; U <= T; U++) {
        cout << "Case #" << U << ": ";
        
    }
}
