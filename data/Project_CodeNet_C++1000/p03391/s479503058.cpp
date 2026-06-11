#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N; cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
    int idx = -1;
    for (int i = 0; i < N; i++) {
        if (A[i] > B[i] && (idx == -1 || B[i] < B[idx])) idx = i;
    }
    if (idx == -1) cout << "0\n";
    else cout << accumulate(begin(A), end(A), 0LL) - B[idx] << '\n';
    return 0;
}