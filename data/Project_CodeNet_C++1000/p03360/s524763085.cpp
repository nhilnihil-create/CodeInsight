#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int exp(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    return a * exp(a, b - 1);
}

int main()
{
    int K;
    vector<int> A(3);
    rep(0, i, 3)
    {
        cin >> A[i];
    }
    cin >> K;
    sort(all(A));
    cout << A[0] + A[1] + A[2] * exp(2, K) << endl;
}