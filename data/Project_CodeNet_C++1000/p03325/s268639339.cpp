#include <bits/stdc++.h>
using namespace std;

int64_t mod = 1000000007;
int64_t large = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int64_t N, tmp;
    cin >> N;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        while (tmp % 2 == 0)
        {
            ans++, tmp /= 2;
        }
    }
    cout << ans;
}