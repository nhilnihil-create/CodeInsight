#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, N;
    cin >> A >> B >> C >> N;

    int count = 0;
    for (int a = A; a >= 0; a--){
        int n = N - 500 * a;
        if (n < 0) {
            continue;
        } else {
            for (int b = B; b >= 0; b--){
                n = N - 500 * a - 100 * b;
                if (n < 0 || n % 50 != 0 || n / 50 > C) {
                    continue;
                } else {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

}