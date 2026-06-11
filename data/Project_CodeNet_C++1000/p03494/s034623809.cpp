#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    
    int ans = 0;
    
    bool flag = true;
    while(flag) {
        for (int i=0; i<n; i++) {
            if (a[i] % 2 != 0) {
                flag = false;
            }
        }
        if (flag) {
            ans++;
            for (int i=0; i<n; i++) {
                a[i] = a[i] / 2;
            }
        }
    }
    cout << ans << endl;
}