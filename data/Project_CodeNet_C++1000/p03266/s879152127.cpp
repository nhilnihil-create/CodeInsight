#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    int a = N / K;
    if (K % 2 == 1) {
        int64_t ans = pow(a, 3);
        cout << ans << endl;
    }
    else{
        int b = a;
        if (N % K >= K / 2) b++;
        int64_t ans = pow(a, 3) + pow(b, 3);
        cout << ans << endl;
    }
}