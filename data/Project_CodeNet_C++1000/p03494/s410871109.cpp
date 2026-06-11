#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    long a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    while(a[0] != -1) {
        for(int i = 0; i < n; i++) {
            if(a[i] % 2 == 0) {
                a[i] /= 2;
            } else {
                cout << ans << endl;
                return 0;
            }
        }
        ans++;
    }
    
    return 0;
}