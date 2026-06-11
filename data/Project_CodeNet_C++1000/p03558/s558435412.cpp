#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
#define rrep(i,n,m) for(int i = (n) - 1; i >=(m); i--)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main()
{
    int k;
    cin >> k;

    vector<pii> edge[k];
    for (int i=0; i<k; ++i)
    {
        edge[i].emplace_back((i+1)%k, 1);
        edge[i].emplace_back((i*10)%k, 0);
    } 

    priority_queue<pii, vector<pii>, greater<pii>> que;
    vector<bool> visited(k, false);
    que.push(make_pair(1, 1));
    while(que.size() > 0)
    {
        int d, now;
        tie(d, now) = que.top();
        que.pop();

        if (now == 0)
        {
            cout << d << endl;
            return 0;
        }
        if (visited[now]) continue;
        visited[now] = true;
        // cout << now << ' ' << d << endl;

        for (auto next_w: edge[now])
            que.push(make_pair(d+next_w.second, next_w.first));
    }
    return 0;
}