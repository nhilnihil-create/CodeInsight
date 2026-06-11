#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> P(M), Y(M);
    vector<vector<int>> city(N + 1);
    for (int i = 0; i < M; i++) {
        cin >> P[i] >> Y[i];
        city[P[i]].push_back(Y[i]);
    }

    for (int i = 1; i <= N; i++) sort(city[i].begin(), city[i].end());

    for (int i = 0; i < M; i++) {
        int x = distance(city[P[i]].begin(), lower_bound(city[P[i]].begin(), city[P[i]].end(), Y[i])) + 1;
        printf("%06d%06d\n", P[i], x);
    }
}