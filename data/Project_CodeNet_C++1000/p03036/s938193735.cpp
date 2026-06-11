#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;
int64_t large = 9223372036854775807;

int main()
{
    int64_t r, D, x;
    cin >> r >> D >> x;
    for (int i = 0; i < 10; i++)
    {
        x = r * x - D;
        cout << x << endl;
    }
}