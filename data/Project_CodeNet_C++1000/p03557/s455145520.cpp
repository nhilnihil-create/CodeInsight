#include <bits/stdc++.h>
using namespace std;

int main()
{
    int64_t N;
    cin >> N;
    vector<int> A_vec(N), B_vec(N), C_vec(N);
    for (int i = 0; i < N; ++i)
        cin >> A_vec.at(i);
    for (int i = 0; i < N; ++i)
        cin >> B_vec.at(i);
    for (int i = 0; i < N; ++i)
        cin >> C_vec.at(i);
    sort(A_vec.begin(), A_vec.end());
    sort(B_vec.begin(), B_vec.end());
    sort(C_vec.begin(), C_vec.end());
    int64_t cnt = 0;
    int64_t idx_A = 0, idx_C = 0;
    for (int i = 0; i < N; ++i) {
        int B = B_vec.at(i);
        while (idx_A < N && A_vec.at(idx_A) < B)
            ++idx_A;
        while (idx_C < N && C_vec.at(idx_C) <= B)
            ++idx_C;
        cnt += idx_A * (N - idx_C);
    }
    cout << cnt << endl;
}
