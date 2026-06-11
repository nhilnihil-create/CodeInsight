#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int N, K;
int a[109];
int dp[100009];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= K; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i - a[j] >= 0 && dp[i - a[j]] == 0)
            {
                dp[i] = 1;
                break;
            }
        }
    }

    if (dp[K])
        cout << "First\n";
    else
        cout << "Second\n";
}