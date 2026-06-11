#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    int N, K;
    cin >> N >> K;
    if ((N - 1) % (K - 1))
    {
        cout << (N - 1) / (K - 1) + 1 << endl;
    }
    else
    {
        cout << (N - 1) / (K - 1) << endl;
    }
}
