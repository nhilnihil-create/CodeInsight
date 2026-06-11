#include<bits/stdc++.h>
using namespace std;
bool vis[101010];
int main()
{
    int K; scanf("%d", &K);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.emplace(0, K);
    while(!Q.empty())
    {
        int dist, node; tie(dist, node) = Q.top(); Q.pop();
        if(vis[node]) continue; vis[node] = true;
        if(node == 0)
        {
            printf("%d\n", dist);
            return 0;
        }
        for(int i=0; i<=9; ++i)
        {
            int targ = K*i+node;
            Q.emplace(dist+targ%10, targ/10);
        }
    }
}