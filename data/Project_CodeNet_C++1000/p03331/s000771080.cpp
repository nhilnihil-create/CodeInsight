#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    uint32_t min = UINT32_MAX;
    for (auto a = 1; a < n; a++) {
        int sum = 0, tmp_a = a, tmp_b = n - a;
        while(tmp_a > 0 || tmp_b > 0) {
            sum += tmp_a % 10 + tmp_b % 10;
            tmp_a /= 10;
            tmp_b /= 10;
        }
        if(min > sum) min = sum;
    }

    cout << min << endl;
    return 0;
}