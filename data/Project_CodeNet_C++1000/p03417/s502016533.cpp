#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    ll N, M;
    cin >> N >> M;
    if ((N >= 2) && (M >= 2))
        cout << (N - 2) * (M - 2) << endl;
    else if (N * M > 1)
    {
        cout << N * M - 2 << endl;
    }
    else
    {
        cout << 1 << endl;
    }
}