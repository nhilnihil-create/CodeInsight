#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
int64_t MAX = 9223372036854775807;
double PI = 3.141592653589793;

bool bekijo(int64_t N)
{
    if (N == 1)
        return true;
    bool x = false;
    for (int i = 2; i <= sqrt(N); i++)
    {
        int tmp = i;
        while (tmp < N)
            tmp *= i;
        if (tmp == N)
            x = true;
    }
    if (x)
        return true;
    else
        return false;
}

int main()
{
    int N;
    cin >> N;
    for (int i = N; i > 0; i--)
        if (bekijo(i))
        {
            cout << i;
            break;
        }
}