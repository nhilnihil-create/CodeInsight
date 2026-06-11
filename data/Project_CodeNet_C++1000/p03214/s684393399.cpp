#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    double sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
    }
    double ave = sum / n;
    double diff = 10000;
    int ans;
    for(int i = 0; i < n; i++) {
        if(diff > abs(ave - a[i])) {
            ans = i;
            diff = abs(ave - a[i]);
        }
    }
    cout << ans << "\n";
    return 0;
}