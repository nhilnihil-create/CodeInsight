#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++)
    {
        int a;
        cin >> a;
        A[a]++;
    }

    sort(A.begin(), A.end());

    // for (int i = 1; i <= N; i++)
    // {
    //     cout << A[i] << " ";
    // }
    // cout << endl;

    int cnt = 0;
    for (int i = 1; i <= N - K; i++)
    {
        cnt += A[i];
    }
    cout << cnt << endl;
    return 0;
}