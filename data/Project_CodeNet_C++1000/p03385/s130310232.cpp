#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    string S;
    cin >> S;
    if (S[0] == S[1] || S[1] == S[2] || S[2] == S[0])
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
}