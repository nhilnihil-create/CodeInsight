#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;


int main() {

    int n, a[100000];

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);
    double r = a[n - 1] / 2.0;
    int mini = 1000000001, ans = 0;
    for(int i = 0; i < n - 1; i++) {
        if(mini > abs(r - a[i])) {
            mini = abs(r - a[i]);
            ans = a[i];
        }
    }

    cout << a[n - 1] << " " << ans << endl;
}
