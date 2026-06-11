#include <iostream>
#include <string>
using namespace std;
using Int = int64_t;
template <class T>
constexpr T gcd(T a, T b) noexcept {
    return a % b ? gcd(b, a % b) : b;
}
template <class T>
constexpr T lcm(T a, T b) noexcept {
    return a * b / gcd(a, b);
}
Int solve() {
    Int N, M;
    string S, T;
    cin >> N >> M >> S >> T;
    Int g = gcd(N, M), l = lcm(N, M);
    for (int i = 0; i < g; i++) {
        if (S[i * N / g] != T[i * M / g]) return -1;
    }
    return l;
}
int main() {
    cout << solve() << endl;
}
