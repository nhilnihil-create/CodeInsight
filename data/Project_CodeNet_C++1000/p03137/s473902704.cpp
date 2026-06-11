#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<long long> X(M);
    for (int i = 0; i < M; ++i) cin >> X[i];
    sort(X.begin(), X.end());
        
    vector<long long> diffs;
    for (int i = 1; i < X.size(); ++i) diffs.push_back(X[i] - X[i-1]);
    sort(diffs.begin(), diffs.end(), greater<long long>());
        
    long long res = X.back() - X[0];
    for (int i = 0; i < min((int)diffs.size(), N-1); ++i) res -= diffs[i];
    cout << res << endl;
}