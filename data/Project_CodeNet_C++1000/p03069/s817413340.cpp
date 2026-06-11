#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)

const int lim = 1000000007;
const int INF = 100000000;

int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;

    //1個の時はコーナーケースとして処理
    if (N == 1)
    {
        cout << 0 << endl;
        return 0;
    }

    int white = 0, black = 0;
    rep(i, N)
    {
        if (S[i] == '.')
            white++;
    }
    int ans = white;
    rep(i, N)
    {
        if (S[i] == '#')
            black++;
        if (S[i] == '.')
            white--;
        ans = min(ans, black + white);
    }
    cout << ans << endl;
    return 0;
}
