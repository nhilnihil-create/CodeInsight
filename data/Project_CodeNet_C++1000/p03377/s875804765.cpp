#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    int A, B, X;
    cin >> A >> B >> X;
    if (A > X || A + B < X)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
}