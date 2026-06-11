#include <bits/stdc++.h>
using namespace std;

int64_t mod = 1000000007;
int64_t large = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int A, B, C, X, ans = 0;
    cin >> A >> B >> C >> X;
    for (int i = 0; i <= A; i++)
        for (int j = 0; j <= B; j++)
            for (int k = 0; k <= C; k++)
                if (i * 500 + j * 100 + k * 50 == X)
                    ans++;
    cout << ans;
}