#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    if (A == B)
    {
        cout << C << endl;
    }
    else if (B == C)
    {
        cout << A << endl;
    }
    else
    {
        cout << B << endl;
    }
}