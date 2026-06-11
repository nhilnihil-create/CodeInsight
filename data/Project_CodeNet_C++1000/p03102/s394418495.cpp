#include <bits/stdc++.h>
using namespace std;

int64_t mod = 1000000007;
int64_t large = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int N, M, C, ans = 0;
    cin >> N >> M >> C;
    vector<int> B(M);
    for (int i = 0; i < M; i++)
        cin >> B[i];
    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        int tmp = 0;
        for (int j = 0; j < M; j++)
            tmp += B[j] * A[i][j];
        tmp += C;
        if (tmp > 0)
            ans++;
    }
    cout << ans;
}