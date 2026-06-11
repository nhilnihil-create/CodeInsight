#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

int A[10];

int main()
{
    rep(i, 0, 4)
    {
        cin >> A[i];
    }
    sort(A, A + 4);
    if (A[0] == 1 && A[1] == 4 && A[2] == 7 && A[3] == 9)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
