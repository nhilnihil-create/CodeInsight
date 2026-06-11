#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, begin, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    int A, B;
    cin >> A >> B;
    if (B % A == 0)
    {
        cout << A + B << endl;
    }
    else
    {
        cout << B - A << endl;
    }
}