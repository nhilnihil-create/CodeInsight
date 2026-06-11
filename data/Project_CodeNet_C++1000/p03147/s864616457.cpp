#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
int64_t MAX = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int N;
    cin >> N;
    vector<int> list(N);
    for (int i = 0; i < N; i++)
        cin >> list[i];
    list.push_back(0);
    reverse(list.begin(), list.end());
    int ans = 0;
    for (int i = 1; i <= 100; i++)
    {
        int tmp = 0;
        for (int j = 0; j < N + 1; j++)
        {
            if (list[j] < i && list[j + 1] >= i)
                tmp++;
        }
        ans += tmp;
    }
    cout << ans;
}