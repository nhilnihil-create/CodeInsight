#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    if (A + B > C + D)
    {
        cout << "Left" << endl;
    }
    else if (A + B == C + D)
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Right" << endl;
    }
}