#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
int64_t MAX = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int A, B;
    cin >> A >> B;
    if (B % A == 0)
        cout << B + A;
    else
        cout << B - A;
}