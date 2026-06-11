#include <iostream>
#include <vector>

int main()
{
    using namespace std;
    int N;
    cin >> N;

    vector<int> a(N);
    vector<int> b(N);
    vector<int> c(N);

    vector<vector<int>> DP(N, vector<int>(3));

    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        cin >> b[i];
        cin >> c[i];
    }

    DP[0][0] = a[0];
    DP[0][1] = b[0];
    DP[0][2] = c[0];

    for (int i = 1; i < N; i++)
    {
        DP[i][0] = max(DP[i - 1][1] + a[i], DP[i - 1][2] + a[i]);
        DP[i][1] = max(DP[i - 1][0] + b[i], DP[i - 1][2] + b[i]);
        DP[i][2] = max(DP[i - 1][0] + c[i], DP[i - 1][1] + c[i]);
    }

    int ans = max(DP[N - 1][0], max(DP[N - 1][1], DP[N - 1][2]));
    cout << ans << endl;
}