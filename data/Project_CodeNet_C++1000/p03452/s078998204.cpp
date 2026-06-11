#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef struct _data
{
    int node;
    int weight;
}Data;
vector<Data> vec[100005];
int N, M, chk[100005], dist[100005], result, Count, resultChk[100005];

void BFS()
{
    queue<Data> q;
    for(int j = 1; j <= N; j++)
    {
        if(chk[j] == 0)
        {
            if(resultChk[j] == 0)
            {
                resultChk[j] = 1;
                Count++;
            }
            memset(dist, -1, sizeof dist);
            q.push({j, 0});
        }
        while(!q.empty())
        {
            Data temp;
            temp = q.front();
            q.pop();
            for(int i = 0; i < vec[temp.node].size(); i++)
            {
                Data next;
                next.node = vec[temp.node][i].node;
                next.weight = temp.weight + vec[temp.node][i].weight;
                if(dist[next.node] != -1 && dist[next.node] != next.weight)
                {
                    result = -1;
                    return;
                }
                dist[next.node] = next.weight;
                chk[next.node]--;
                if(chk[next.node] == 0)
                {
                    if(resultChk[next.node] == 0)
                    {
                        resultChk[next.node] = 1;
                        Count++;
                    }
                    q.push(next);
                }
            }
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++)
    {
        int l, r, d;
        scanf("%d %d %d", &l, &r, &d);
        vec[l].push_back({r, d});
        chk[r]++;
    }
    BFS();
    if(Count != N)
    {
        result = -1;
    }
    result == 0 ? printf("Yes") : printf("No");
}