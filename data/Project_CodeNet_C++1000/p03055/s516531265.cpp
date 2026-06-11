#include <iostream>
#define maxn 200005

using namespace std;

struct edge{
    int to,next;
}edge[maxn*2];
int head[maxn];int top = 1;
int n;

void add(int s,int t)
{
    edge[top].next = head[s];
    edge[top].to = t;
    head[s] = top;
    top++;
}

int maxx,ii;
bool vis[maxn];
void DFS(int s,int step)
{
    if(step > maxx){
        maxx = step;
        ii = s;
    }
    vis[s] = 1;
    for(int i = head[s];i;i = edge[i].next)
        if(!vis[edge[i].to])DFS(edge[i].to,step+1);
}

int main()
{
    int a,b;
    cin >> n;
    for(int i = 1;i < n;i++)
    {
        cin >> a >> b;
        add(a,b);
        add(b,a);
    }
    DFS(1,0);
    for(int i = 0;i <= n;i++)
        vis[i] = 0;
    DFS(ii,0);
    maxx++;
    if(maxx % 3 == 2)cout << "Second" << endl;
    else cout << "First" << endl;
    return 0;
}
