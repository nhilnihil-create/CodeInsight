#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
int64_t MAX = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int N;
    cin >> N;

    vector<vector<pair<int, int>>> list(N);
    int p, q, r;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> p >> q >> r;
        p--, q--;
        list[p].push_back({q, r}), list[q].push_back({p, r});
    }

    vector<bool> arrived(N, false); //訪問済みかどうか
    vector<int> length(N);          //始点からの距離
    queue<int> que;                 //訪問予定

    que.push(0);
    arrived[0] = true;
    length[0] = 0;
    int search, now, dis;
    while (!que.empty())
    {
        now = que.front();
        que.pop();
        for (int i = 0; i < list[now].size(); i++)
        {
            search = list[now][i].first;
            dis = list[now][i].second;
            if (!arrived[search]) //未訪問
            {
                arrived[search] = true;
                length[search] = (length[now] + dis) % 2;
                que.push(search);
            }
        }
    }
    for (auto x : length)
        cout << x << endl;
}