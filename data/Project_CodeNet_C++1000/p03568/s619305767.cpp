#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = pow(3, n);
    int counter = 1;
    for(int i = 0; i < n; i++) {
        if(a[i] % 2 == 0) {
            counter *= 2;
        }
    }
    cout << ans - counter << "\n";
    return 0;
}