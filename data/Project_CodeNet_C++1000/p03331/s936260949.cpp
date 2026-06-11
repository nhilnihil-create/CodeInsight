#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;

    int ans = 0;
    int ano_N = N;
    while(N > 0) {
        ans += N%10;
        N /= 10;
    }
    int num = 1;
    for(int i = 0; i < 6; i++) {
        num *= 10;
        if(ano_N == num) {
            ans = 10;
        }
    }
    cout << ans << endl;
}