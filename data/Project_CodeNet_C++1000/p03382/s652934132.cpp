#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long comb(int n, int r) {
    long long ans = 1;
    for (int i = 0; i < r; i++) ans = ans*(n - i)/(i + 1);
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end(), greater<int>());

    vector<int> b(n);
    b[0] = a[0];
    for (int i = 1; i < n; i++) b[i] = abs(2*a[i] - b[0]);
    int ans = 1, diff = b[1];
    for (int i = 2; i < n; i++) {
        if (b[i] < diff) {
            ans = i;
            diff = b[i];
        }
    }

    cout << a[0] << ' ' << a[ans] << endl;
    return 0;
}