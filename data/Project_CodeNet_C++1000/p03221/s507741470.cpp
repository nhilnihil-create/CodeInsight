#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<int> P(M), Y(M);
    for (int i = 0; i < M; i++) cin >> P[i] >> Y[i];
    vector<int> ord[100100];
    for (int i = 0; i < M; i++) ord[P[i]].push_back(Y[i]);
    for (int i = 1; i <= N; i++) sort(ord[i].begin(), ord[i].end());
    for (int i = 0; i < M; i++) {
        int n = lower_bound(ord[P[i]].begin(), ord[P[i]].end(), Y[i]) - ord[P[i]].begin() + 1;
        printf("%06d%06d\n", P[i], n);
    }
    return 0;
}