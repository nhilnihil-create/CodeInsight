#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<int> P(M), Y(M), ord[100010]; 
    for (int i = 0; i < M; i++) {
        cin >> P[i] >> Y[i];
        ord[P[i]].push_back(Y[i]);
    }
    for (int i = 1; i <= N; i++) sort(ord[i].begin(), ord[i].end());
    for (int i = 0; i < M; i++) {
        printf("%06d", P[i]);
        int d = lower_bound(ord[P[i]].begin(), ord[P[i]].end(), Y[i]) - ord[P[i]].begin() + 1;
        printf("%06d\n", d);
    }
    return 0;
}