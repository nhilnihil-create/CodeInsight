#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<pair<int, int>> qCnt(q);
    rep (i, q)
        cin >> qCnt[i].first >> qCnt[i].second;

    vector<int> acCnt(n, 0);
    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] == 'A' && s[i] == 'C')
            acCnt[i]++;
        acCnt[i] += acCnt[i - 1];
    }
    
    rep (i, q)
        cout << acCnt[qCnt[i].second - 1] - acCnt[qCnt[i].first - 1] << endl;

    return 0;
}