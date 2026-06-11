#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, y;
    cin >> n >> y;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; i+j <= n; j++) {
            int k = n-i-j;
            int sum = i*10000 + j*5000 + k*1000;
            if (sum == y) {
                printf("%d %d %d",i,j,k);
                return 0;
            }
        }
    }

    cout << "-1 -1 -1" << endl;
}