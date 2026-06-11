#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector a(n,0);
    for (int i=0; i<n; i++) cin >> a[i];

    int ans = a[0];
    for (int i=0; i<n; i++) ans = gcd(ans, a[i]);
    cout << ans << endl;
}