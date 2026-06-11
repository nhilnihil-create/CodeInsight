#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N,K;
    cin >> N >> K;
    
    if ( K % 2 == 0 ) {
        int64_t k2 = K / 2;
        int64_t num0 = N / K;
        int64_t num1 = N / k2 - num0;
        //cout << num0 << num1 << endl;
        cout << num0 * num0 * num0 + num1 * num1 * num1 << endl;
    } else {
        int64_t num = N / K;
        cout << num * num * num << endl;
    }
}
