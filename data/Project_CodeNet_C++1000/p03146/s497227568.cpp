#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int s;
    cin >> s;

    vector<int> numCnt(100100, 0);
    numCnt[s]++;
    int a = s;
    int ans = 1;
    while (1)
    {
        ++ans;
        if (a % 2)
        {
            a = 3 * a + 1;
            numCnt[a]++;
        }
        else
        {
            a /= 2;
            numCnt[a]++;
        }

        if (numCnt[a] >= 2)
        {
            cout << ans << endl;
            return 0;
        }
    }

    return 0;
}