#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
using Int = long long;
#define MOD 1000000007
int ADD(int x, int y) { return ((Int)x + y) % MOD; }
int MUL(int x, int y) { return (Int)x * y % MOD; }
int POW(int x, int y) {
    int result = 1;
    while (y > 0) {
        if (y & 1) result = MUL(result, x);
        x = MUL(x, x);
        y >>= 1;
    }
    return result;
}
int FACT(int x) {
    int result = 1;
    for (int i = 1; i <= x; i++) {
        result = MUL(result, i);
    }
    return result;
}
int INV(int x) { return POW(x, MOD-2); }
int S[100001]; // 1/1 + 1/2 + ... + 1/n
int main()
{
    for (int i = 1; i <= 100000; i++) {
        S[i] = ADD(S[i-1], INV(i));
    }
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    int result = 0;
    for (int j = 0; j < N; j++) {
        result = ADD(result, MUL(A[j], S[j+1] + S[N-j] - 2));
    }
    int sum = 0;
    for (int i = 0; i < N; i++) sum = ADD(sum, A[i]);
    cout << MUL(FACT(N), ADD(result, sum)) << endl;
    return 0;
}
