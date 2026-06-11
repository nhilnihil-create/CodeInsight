#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    vector<string> S(3);
    rep(0, i, 3)
    {
        cin >> S[i];
    }
    cout << S[0][0] << S[1][1] << S[2][2] << endl;
}