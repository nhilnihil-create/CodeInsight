#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;


    if (n%2) {
        cout << (n*(n-1))/2 - n/2 << "\n";
        for (int i = 1; i <= n; i++) {
            for (int j = i+1; j <= n; j++) {
                if (i+j==n) continue;
                cout << i << " " << j << "\n";
            }
        }

    } else {
        cout << n*(n-2)/2 << "\n";
        for (int i = 1; i <= n; i++) {
            for (int j = i+1; j <= n; j++) {
                if (i+j==n+1) continue;
                cout << i << " " << j << "\n";
            }
        }
    }


    return 0;
}
