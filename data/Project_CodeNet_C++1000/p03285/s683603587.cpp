#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main()
{
    int N;
    cin >> N;
    bool ans = false;
    for (int f = 0; f <= 25; f++)
    {
        for (int s = 0; s <= 15; s++)
        {
            if (N == f * 4 + s * 7)
                ans = true;
        }
    }
    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}