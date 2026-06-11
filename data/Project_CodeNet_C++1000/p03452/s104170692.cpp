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
int N, M, chk[100005], dist[100005], result;

void BFS()
{
    queue<Data> q;
    for(int j = 1; j <= N; j++)
    {
        if(chk[j] == 0)
        {
            chk[j] = 1;
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
                if(chk[next.node] == 0)
                {
                    chk[next.node] = 1;
                    dist[next.node] = next.weight;
                    q.push(next);
                }
                else
                {
                    if(dist[next.node] != next.weight)
                    {
                        result = 1;
                        return;
                    }
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
        vec[r].push_back({l, -d});
    }
    BFS();
    for(int i = 1; i <= N; i++)
    {
        if(chk[i] == 0)
        {
            result = 1;
            break;
        }
    }
    result == 0 ? printf("Yes") : printf("No");
}