#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
int64_t MAX = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int N, M;
    cin >> N >> M;
    if (N < M)
    {
        vector<int> list(M), dis(M - 1);
        for (int i = 0; i < M; i++)
            cin >> list[i];
        sort(list.begin(), list.end());

        for (int i = 0; i < M - 1; i++)
            dis[i] = list[i + 1] - list[i];
        sort(dis.begin(), dis.end());
        reverse(dis.begin(), dis.end());
        
        int ans = list[M - 1] - list[0];
        for (int i = 0; i < N - 1; i++)
            ans -= dis[i];
        cout << ans;
    }
    else
        cout << 0;
}