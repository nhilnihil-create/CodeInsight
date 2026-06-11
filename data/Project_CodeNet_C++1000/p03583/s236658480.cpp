#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    long long num;
    long long tmp1, tmp2;
    cin >> num;

    for (long long h = 1; h <= 3500; h++) {
        for (long long n = 1; n <= 3500; n++) {
            tmp1 = num * h * n;
            tmp2 = 4 * h * n - num * n - num * h;
            
            if (tmp2 > 0 && tmp1 % tmp2 == 0) {
                long long tmp3 = tmp1 / tmp2;
                cout << h << " " << n << " " << tmp3;
                return 0;
            }
        }
    }
    //
}