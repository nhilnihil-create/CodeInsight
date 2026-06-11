#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    int a, b;
    cin >> a >> b;
    vector<int> A(1000), B(999);
    A[0] = 0;
    rep(1, i, 1001)
    {
        A[i] = A[i - 1] + i;
        B[i] = A[i] - A[i - 1];
        if (B[i] == b - a)
        {
            cout << A[i] - b;
            return 0;
        }
    }
}
