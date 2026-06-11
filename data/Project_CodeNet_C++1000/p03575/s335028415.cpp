#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
int64_t MAX = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> count(N);
    vector<vector<int>> list(N);
    vector<pair<int, int>> bridge;
    for (int i = 0; i < M; i++)
    {
        int p, q;
        cin >> p >> q;
        p--, q--;
        list[p].push_back(q), list[q].push_back(p);
        count[p]++, count[q]++;
        bridge.push_back(make_pair(p, q));
    }
    int ans = 0;
    for (int i = 0; i < M; i++)
    {
        vector<bool> arrived(N, false); //訪問済みかどうか
        queue<int> que;                 //訪問予定
        int number = 1;                 //何箇所訪れたか

        que.push(0);
        arrived[0] = true;
        while (!que.empty())
        {
            int now = que.front();
            que.pop();
            for (int j = 0; j < count[now]; j++)
            {
                int search = list[now][j];
                auto tmp = make_pair(min(now, search), max(now, search));
                if (tmp == bridge[i])
                    continue;
                if (!arrived[search]) //未訪問
                {
                    arrived[search] = true;
                    que.push(search);
                    number++;
                }
            }
        }
        if (number != N)
            ans++;
    }
    cout << ans;
}