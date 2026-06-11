#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
using namespace std;

int N; vector<int> A,B,C;
void input()
{
    cin >> N;
    A.resize(N);
    B.resize(N);
    C.resize(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];
    for (int i = 0; i < N; ++i) cin >> C[i];
}

void solve()
{
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(C.begin(),C.end());

    long long cnt = 0;
    for (int i = 0; i < N; ++i) {
        auto itr1 = lower_bound(A.begin(),A.end(),B[i]);
        auto itr2 = upper_bound(C.begin(),C.end(),B[i]);
        // assert(itr1 - A.begin() >= 0);
        // assert(C.end() - itr2 >= 0);
        cnt += (itr1 - A.begin()) * (C.end() - itr2);
    }
    cout << cnt << endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    // int ti = clock();
    input();
    solve();
    // printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
    return 0;
}