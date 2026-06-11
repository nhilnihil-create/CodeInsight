#include <bits/stdc++.h>
using namespace std;

int64_t count(const vector<int> &A_vec, const vector<int> &C_vec, int B)
{
    auto lb_A = lower_bound(A_vec.begin(), A_vec.end(), B);
    auto ub_C = upper_bound(C_vec.begin(), C_vec.end(), B);
    int64_t cnt_A = lb_A - A_vec.begin();
    int64_t cnt_C = C_vec.end() - ub_C;
    return cnt_A * cnt_C;
}

int main()
{
    int N;
    cin >> N;
    vector<int> A_vec(N), B_vec(N), C_vec(N);
    for (int i = 0; i < N; ++i)
        cin >> A_vec.at(i);
    for (int i = 0; i < N; ++i)
        cin >> B_vec.at(i);
    for (int i = 0; i < N; ++i)
        cin >> C_vec.at(i);
    sort(A_vec.begin(), A_vec.end());
    sort(C_vec.begin(), C_vec.end());
    int64_t cnt = 0;
    for (int i = 0; i < N; ++i) 
        cnt += count(A_vec, C_vec, B_vec.at(i));
    cout << cnt << endl;
}
