#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
int64_t MAX = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    string S, T;
    cin >> S >> T;
    bool x = false;
    int y = S.size();
    for (int i = 0; i < y; i++)
    {
        bool z = true;
        for (int j = 0; j < y; j++)
        {
            if (S[(i + j) % y] != T[j])
                z = false;
        }
        if(z)
            x = true;
    }
    cout << (x ? "Yes" : "No");
}