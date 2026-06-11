#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int sed(int N) {
    int a = N;
    int c = 0;
    bool b = true;
    while(b){
        if (a == 0) {
            b = false;
        }
        c += a % 10;
        a /= 10;
    }
    return c;
}
int main() {
    int N; cin >> N;
    int ans = 10e9 + 1;
    for (int i = 1; i <= N / 2; ++i) {
        int a = N - i;
        ans = min(ans, sed(i) + sed(a));
    }
    printf("%d\n", ans);
}
