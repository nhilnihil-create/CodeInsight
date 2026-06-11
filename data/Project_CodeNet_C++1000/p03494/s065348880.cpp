#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int cnt = 0;
    bool ok = true;
    while (ok == true) {
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0) a[i] = a[i] / 2;
            else{
                ok = false;
                break;
            } 
        }
        if (ok == true) cnt++;
    }
    cout << cnt << endl;
    return 0;
}