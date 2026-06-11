#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N;
    cin >> N;
    
    cout << N * (N - 1) / 2 - N / 2 << endl;
    if (N % 2) {
        for (int i = 1; i <= N; ++i) {
            for (int j = i + 1; j <= N; ++j) {
                if (i + j != N) {
                    cout << i << " " << j << endl;
                }
            }
        }
    } else {
        for (int i = 1; i <= N; ++i) {
            for (int j = i + 1; j <= N; ++j) {
                if (i + j != N + 1) {
                    cout << i << " " << j << endl;
                }
            }
        }
    }
    return 0;
}
