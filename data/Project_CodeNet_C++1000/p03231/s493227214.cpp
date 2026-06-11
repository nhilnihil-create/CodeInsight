#include <iostream>
#include <string>
using namespace std;
using Int = int64_t;
template <class T> T gcd(T a, T b) { return a % b ? gcd(b, a % b) : b; }
template <class T> T lcm(T a, T b) { return a * b / gcd(a, b); }
Int solve() {
    Int N, M;
    string S, T;
    cin >> N >> M >> S >> T;
    Int L = lcm(N, M);
    Int g = gcd(N, M), n = N / g, m = M / g;
    for (Int k = 0; k < g; k++) {
        Int a = k * n, b = k * m;
        if (S[a] != T[b]) return -1;
    }
    return L;
}
int main() {
    cout << solve() << endl;
}
