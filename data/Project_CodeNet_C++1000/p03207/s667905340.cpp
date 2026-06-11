#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N; cin >> N;
    vector<int> P(N, 0);
    int tmp = 0, j = 0;
    for(int i = 0; i < N; i++) {
        cin >> P[i];
        if (tmp <= P[i]) {
            tmp = P[i], j = i;
        }
    }
    P[j] /= 2;
    int sum = 0;
    for (int i = 0; i < N; i++) sum += P[i];
    printf("%d\n", sum);
}
