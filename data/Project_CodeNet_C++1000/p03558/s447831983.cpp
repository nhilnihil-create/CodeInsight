#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> P;
const int maxn=2e5+100;
int k;
bool vis[maxn];
 
int main()
{
    //freopen("1.txt","r",stdin);
    while (scanf("%d",&k)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        deque<P> q;
        q.push_front(make_pair(1,1));
        while (!q.empty())
        {
            auto t=q.front(); q.pop_front();
            if (vis[t.first]) continue;
            vis[t.first]=1;
            if (t.first==0)
            {
                printf("%d\n",t.second);
                break;
            }
            q.push_front(make_pair(t.first*10%k,t.second));
            q.push_back(make_pair((t.first+1)%k,t.second+1));
        }
    }
    return 0;
}