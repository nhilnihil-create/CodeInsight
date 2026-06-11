#include <bits/stdc++.h>
using namespace std;

int N, K;
const int n = 200010;
int A[n];

int main()
{
    cin >> N >> K;

    for (int i = 0; i < n; i++)
    {
        A[i] = 0;
    }

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        A[x]++;
    }

    int k = 0;
    int B[N];

    for (int i = 0; i < N; i++)
    {
        B[i] = 0;
    }

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] != 0)
        {
            k++;
            B[j] = A[i];
            j++;
        }
    }

    if (k < K)
    {
        cout << 0 << endl;
        return 0;
    }

    sort(B, B + k);

    int to_be_modified = k - K;

    int ans = 0;

    for (int i = 0; i < to_be_modified; i++)
    {
        ans += B[i];
    }

    cout << ans << endl;

    return 0;
}
