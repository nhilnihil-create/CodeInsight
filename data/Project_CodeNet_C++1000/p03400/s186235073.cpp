#include <bits/stdc++.h>
using namespace std;

int64_t mod = 1000000007;
int64_t large = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int N, D, ans, tmp;
    cin >> N >> D >> ans;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        ans += (D - 1) / tmp + 1;
    }
    cout << ans;
}