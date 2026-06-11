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
    int a[5] = {}, k, z = 1000;
    for (int i = 0; i < 5; i++) cin >> a[i];
    for (int i = 0; i < 120; i++) {
        int c = 0;
        for (int j = 0; j < 5; j++) {
            c += a[j];
            if (j != 4) while (c % 10) c++;
        }
        z = min(z, c);
        next_permutation(a, a + 5);
    }
    cout << z;
    int T;
    cin >> T;
    for (int U = 1; U <= T; U++) {
        cout << "Case #" << U << ": ";
        
    }
}
