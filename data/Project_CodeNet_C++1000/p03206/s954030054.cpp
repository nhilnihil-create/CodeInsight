#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    int D;
    cin >> D;
    string S = "Christmas";
    string eve = " Eve";
    rep(0, i, 25 - D)
    {
        S += eve;
    }
    cout << S << endl;
}