#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, y;
    cin >> n >> y;
    int a = -1, b = -1, c = -1;
    for(int i=0; i<=n; i++) {
        for (int j=0; i+j<=n; j++) {
            int k = n - i - j;
            int total = 10000 * i + 5000 * j + 1000 * k;
            if (total == y) {
                a = i;
                b = j;
                c = k;
            }
        }
    }
    
    
    cout << a << " " << b << " " << c << endl;
}
