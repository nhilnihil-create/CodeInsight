#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    int R;
    cin >> R;
    if (R >= 2800)
    {
        cout << "AGC" << endl;
    }
    else if (R >= 1200)
    {
        cout << "ARC" << endl;
    }
    else
    {
        cout << "ABC" << endl;
    }
}