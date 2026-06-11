#include <bits/stdc++.h>
using namespace std;

int64_t mod = 1000000007;
int64_t large = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> eigyo(N, vector<int>(10));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 10; j++)
            cin >> eigyo[i][j];

    vector<vector<int>> rieki(N, vector<int>(11));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 11; j++)
            cin >> rieki[i][j];
    int64_t ans = -mod;
    for (int i = 1; i < (1 << 10); i++)
    {
        bitset<10> bt(i);
        int64_t tmp = 0;
        for (int j = 0; j < N; j++)
        {
            int count = 0;
            for (int k = 0; k < 10; k++)
            {
                if (bt.test(k) && eigyo[j][k])
                    count++;
            }
            tmp += rieki[j][count];
        }
        ans = max(ans, tmp);
    }
    cout << ans;
}