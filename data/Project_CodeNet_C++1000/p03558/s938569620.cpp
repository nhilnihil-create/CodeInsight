#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<deque>
#include<stack>
#include<string>
#include<cstring>
#include<map>
using namespace std;
int k;
struct pa{
    int x,y;
};
deque<pa>p;
bool vis[10000000];
void bfs(){
    while(p.size())
    {
        pa n=p.front();p.pop_front();
        if(vis[n.x])
        {
            continue;
        }
        vis[n.x]=1;
        if(!n.x)
        {
            cout<<n.y;
            return;
        }
        pa a;
        a.x=n.x*10%k;a.y=n.y;
        p.push_front(a);
        a.x=(n.x+1)%k;a.y=n.y+1;
        p.push_back(a);
    }
}
int read()
{
    int x=0,f=1;
    char ch;
    while((ch=getchar())<'0'||ch>'9')
    {
        if(ch=='-')
        {
            x=-1;
        }
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-48;
        ch=getchar();
    }
    return x*f;
}
int main()
{
    k=read();
    pa b;
    b.x=1;b.y=1;
    p.push_front(b);
    bfs();
    return 0;
}

       

