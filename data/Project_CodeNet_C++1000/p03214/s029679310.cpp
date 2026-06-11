#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N; cin >> N;
    vector<int> A(N, 0);
    int ave = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i]; ave += A[i];
    }
    double ave_t = ave / (N * 1.0);
    vector<double> diff(N, 0.0);
    double mini = 10e8;
    for (int i = 0; i < N; ++i) {
        diff[i] = abs(ave_t - A[i]);
        mini = min(mini, diff[i]);
    }
    for (int i = 0; i < N; ++i) {
        if (mini == diff[i]) {
            printf("%d\n", i);
            return 0;
        }
    }
}
