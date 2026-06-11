#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
    int n;
    scanf("%d", &n);
    vector<string> w(n);
    rep(i, n) cin >> w[i];
    bool ans = true;
    rep(i, n - 1)
    {
        int l = w[i].size();
        if (w[i][l - 1] != w[i + 1][0])
        {
            ans = false;
            break;
        }
    }
    sort(w.begin(), w.end());
    rep(i, n) {
        for(int j = i + 1; j < n; j++) {
            if(w[i] == w[j]) ans = false;
            break;
        }
    }

    if (ans)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}