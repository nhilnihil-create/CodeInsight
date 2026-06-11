#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    string S1, S2;
    cin >> S1 >> S2;
    reverse(all(S1));
    if (S1 == S2)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}