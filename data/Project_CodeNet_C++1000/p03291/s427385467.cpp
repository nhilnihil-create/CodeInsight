#include <iostream>
#include <string>

using namespace std;
constexpr int64_t MOD = 1'000'000'007;

int main(void) {
    string S;
    cin >> S;
    int N = S.size();
    int64_t Q = 1;
    int64_t countA = 0;
    int64_t countAB = 0;
    int64_t countABC = 0;
    for(int i=0; i<N; ++i) {
        if(S[i] == 'A') {
            countA = (countA + Q) % MOD;
        } else if(S[i] == 'B') {
            countAB = (countAB + countA) % MOD;
        } else if(S[i] == 'C') {
            countABC = (countABC + countAB) % MOD;
        } else {
            countABC = (countABC * 3 + countAB) % MOD;
            countAB = (countAB * 3 + countA) % MOD;
            countA = (countA * 3 + Q) % MOD;
            Q = (Q * 3LL) % MOD;
        }
    }
    cout << countABC % MOD << endl;
    return 0;
}
