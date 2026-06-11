#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int prea; cin >> prea;
    int ans = 0;
    for (int i=1; i<n; ++i) {
        int a; cin >> a;
        if (prea == a) {
            ans++;
            prea = a;
            cin >> a;
            i++;
        }
        prea = a;
    }
    cout << ans << endl;
}