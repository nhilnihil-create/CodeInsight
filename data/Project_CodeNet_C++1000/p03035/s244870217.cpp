#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;
int64_t large = 9223372036854775807;

int main()
{
    int A, B;
    cin >> A >> B;
    if(A>=13)
        cout << B;
    else if (A >= 6)
        cout << B / 2;
    else
        cout << 0;
}