#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
int64_t MAX = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    string S;
    cin >> S;
    for (int i = 0; i < 3; i++)
    {
        if (S[i] == '1')
            cout << '9';
        else if (S[i] == '9')
            cout << '1';
        else
            cout << S[i];
    }
}