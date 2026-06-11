#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x, y, z;
    cin >> x >> y >> z;

    int K;
    cin >> K;
    vector<long long> A(x);
    vector<long long> B(y);
    vector<long long> C(z);
    for (int i = 0; i < x; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < y; ++i) {
        cin >> B[i];
    }
    for (int i = 0; i < z; ++i) {
        cin >> C[i];
    }

    if (A.size() > B.size()) {
        swap(A, B);
    }
    if (A.size() > C.size()) {
        swap(A, C);
    }
    if (B.size() > C.size()) {
        swap(B, C);
    }
    int n = A.size();
    int m = B.size();
    int l = C.size();

    vector<long long> sums;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sums.push_back(A[i] + B[j]);
        }
    }
    sort(sums.begin(), sums.end(), greater<long long>());
    if (sums.size() > K) {
        sums.resize(K);
    }
    vector<long long> X;
    for (auto x : C) {
        for (auto y : sums) {
            X.push_back(x + y);
        }
    }
    sort(X.begin(), X.end(), greater<long long>());

    for (int i = 0; i < K; ++i) {
        cout << X[i] << '\n';
    }


    return 0;
}