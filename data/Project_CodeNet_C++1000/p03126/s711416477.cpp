#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> favo(M + 1, 0);
    for (int i = 0; i < N; i++)
    {
        int K;
        cin >> K;
        for (int j = 0; j < K; j++)
        {
            int a;
            cin >> a;
            favo[a]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < M + 1; i++)
    {
        if (favo[i] == N)
        {
            ++ans;
        }
    }
    cout << ans << endl;
}