#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n+2);
    int sum = 0;
    for (int i = 1; i < n + 1; i++) {
        cin >> a[i];
        sum += abs(a[i] - a[i-1]);
        if (i == n) sum += abs(a[i]);
    }

    for (int i = 1; i < n+1; i++) {
        int ans = sum + abs(a[i-1] - a[i+1]) - abs(a[i-1] - a[i]) - abs(a[i] - a[i+1]);
        cout << ans << endl;
    }
}