#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string S;
    cin >> S;

    int ans = 700;
    for (char t : S)
    {
        if (t == 'o')
        {
            ans += 100;
        }
    }

    cout << ans << endl;

    return 0;
}