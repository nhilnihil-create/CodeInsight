#include <bits/stdc++.h>
using namespace std;

int64_t mod = 1000000007;
int64_t large = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int N, K, tmp, ans = mod;
    cin >> N >> K;
    vector<int> list(N);
    for (int i = 0; i < N; i++)
        cin >> list[i];
    sort(list.begin(), list.end());
    for (int i = 0; i < N - K + 1; i++)
    {
        tmp = list[i + K - 1] - list[i];
        ans = min(ans, tmp);
    }
    cout << ans;
}