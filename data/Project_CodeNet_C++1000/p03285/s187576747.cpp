#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
int64_t MAX = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int N;
    cin >> N;
    bool x = false;
    for (int i = 0; i <= N / 7; i++)
        if ((N - i * 7) % 4 == 0)
            x = true;
    cout << (x ? "Yes" : "No");
}