#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N; cin >> N;
    vector<pair<pair<string, int>, int>> P(N);
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> P[i].first.first >> a;
        P[i].first.second = -a, P[i].second = i;
    }
    sort(P.begin(), P.end());
    for (int i = 0; i < N; ++i) cout << P[i].second + 1 << endl;
}
