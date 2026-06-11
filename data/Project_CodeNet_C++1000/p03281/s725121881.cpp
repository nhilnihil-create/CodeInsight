#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,ans=0;
    cin >> N;
    for (int i = 105; i <= N; i+=2) {
        int num_i = 0;
        for (int j = 1; j < sqrt(i); j++) {
            if (i%j==0 && j!=i%j) {
                num_i += 2;
            }
            else if (i%j==0 && j==i%j) {
                num_i++;
            }
        }
        if (num_i == 8) {
            ans++;
        }
    }
    cout << ans << endl;
}