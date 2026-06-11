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
    int N, A, B; cin >> N >> A >> B;
    int sum = 0;
    for (int i = 1; i <= N; ++i) if (A <= sed(i) && sed(i) <= B) sum += i;
    printf("%d\n", sum);
}
