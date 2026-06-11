#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (abs(a - c) > d)
    {
        if (abs(a - b) > d || abs(b - c) > d)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
    else
    {
        cout << "Yes" << endl;
    }
}