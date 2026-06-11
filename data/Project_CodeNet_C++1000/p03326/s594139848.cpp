#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define printYes() cout << "Yes" << endl;
#define printNo() cout << "No" << endl;
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<priority_queue<long long>> cakeScore(8);
    rep(i, N)
    {
        long long x, y, z;
        cin >> x >> y >> z;
        cakeScore[0].push(x + y + z);
        cakeScore[1].push(x + y - z);
        cakeScore[2].push(x - y + z);
        cakeScore[3].push(x - y - z);
        cakeScore[4].push(-x + y + z);
        cakeScore[5].push(-x + y - z);
        cakeScore[6].push(-x - y + z);
        cakeScore[7].push(-x - y - z);
    }
    long long ans = 0;
    rep(i, 8)
    {
        long long score = 0;
        rep(j, M)
        {
            score += cakeScore[i].top();
            cakeScore[i].pop();
        }
        ans = max(ans, score);
    }
    cout << ans << endl;
    return 0;
}