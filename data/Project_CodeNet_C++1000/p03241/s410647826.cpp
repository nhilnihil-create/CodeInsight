#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int mod = 1000000007;
int64_t large = 9223372036854775807;

int main()
{
    int N, M;
    cin >> N >> M;

    for (int i = M / N; i >= 1; i--)
    {

        if (M % i == 0)
        {
            cout << i;
            break;
        }
    }
}