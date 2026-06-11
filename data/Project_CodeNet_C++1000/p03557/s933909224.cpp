#include <bits/stdc++.h>
using namespace std;































int main () {
double t1 = clock();

    int N;
    cin >> N;
    
    vector<int64_t> A(N), B(N), C(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    int64_t count = 0;

    for (int i = 0; i < N; i++) {
        auto C_low = lower_bound(C.begin(), C.end(), B[i] + 1); // >= B[i] + 1 になる最小のインデックス
        auto A_upp = upper_bound(A.begin(), A.end(), B[i] - 1); // > B[i] - 1 になる最小のインデックス
        count += distance(C_low, C.end()) * distance(A.begin(), A_upp);
        // cout << distance(A.begin(), A_upp) << " ";
        // cout << distance(C_low, C.end()) << " ";
        // cout << count << endl;
    }

    cout << count << endl;
    double t2 = clock();
    // cout << ((t2 - t1) / CLOCKS_PER_SEC) << endl;
}