#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;

    int sum = 0, maxLen = 0;
    rep (i, n)
    {
        int l;
        cin >> l;
        sum += l;
        maxLen = max(l, maxLen);
    }

    cout << (maxLen < sum - maxLen ? "Yes" : "No") << endl;
    return 0;
}