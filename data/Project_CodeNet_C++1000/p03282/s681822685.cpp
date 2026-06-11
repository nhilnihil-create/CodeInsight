#include <bits/stdc++.h>
using namespace std;

int64_t mod = 1000000007;
int64_t large = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int64_t K;
    string S;
    cin >> S >> K;
    bool x = true;
    for (int i = 0; i < min((int64_t)S.size(),K); i++)
    {
        if (S[i] != '1')
        {
            cout << S[i];
            x = false;
            break;
        }
    }
    if(x)
        cout << 1;
}