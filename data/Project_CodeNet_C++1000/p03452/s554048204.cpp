#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int c()
{
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n));
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    int max_count = 0;
    for(int i = 0; i < n; i++)
    {
        int j = 0;
        int count = 0;
        bool flag = true;
        for(int k = 0; k < n; k++)
        {
            count += a[j][k];
            if(k == i && flag) {
                j = 1;
                k--;
                flag = false;
            }
        }
        max_count = max(count, max_count);
    }
    cout << max_count << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n); //first 行き先, second コスト
    vector<bool> used(n, false);    //使用済みフラグ
    vector<int> result(n, 0);   //値
    auto add_edge = [&](int from, int to, int cost)
    {
        //fromからtoへ重みcostの辺を追加する
        graph[from].push_back({to, cost});
    };
    auto bfs = [&](int s)
    {
        //sからbfsを行いながら数を決定していく
        queue<int> q;
        q.push(s);
        used[s] = true;
        result[s] = 0;
        while (!q.empty())
        {
            int current = q.front();
            q.pop();
            for(int i = 0; i < graph[current].size(); i++)
            {
                int next = graph[current][i].first;
                if(!used[next])
                {
                    q.push(next);
                    used[next] = true;
                    result[next] = result[current] + graph[current][i].second;
                }else{
                    //値に矛盾がないか確認
                    int temp = result[current] + graph[current][i].second;
                    if(result[next] != temp)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    };
    for(int i = 0; i < m; i++)
    {
        int l, r, d;
        cin >> l >> r >> d;
        add_edge(l - 1, r - 1, d);
        add_edge(r - 1, l - 1, -d);
    }
    //値を割り振り
    for(int i = 0; i < n; i++)
    {
        if(!used[i])
        {
            if(!bfs(i))
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
