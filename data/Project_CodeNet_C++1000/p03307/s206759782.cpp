#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main(void) {
    int N;cin>>N;
    if (N % 2 == 0) cout << N << endl;
    else cout << lcm(2, N) << endl;
    return 0;
}