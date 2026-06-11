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
    int a[5] = {}, k;
    for (int i = 0; i < 5; i++) cin >> a[i];
    cin >> k;
    if (a[4] - a[0] > k) cout << ":(";
    else cout << "Yay!";
    return 0;
    int T;
    cin >> T;
    for (int U = 1; U <= T; U++) {
        cout << "Case #" << U << ": ";
        
    }
}
