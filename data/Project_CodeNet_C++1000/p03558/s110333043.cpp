#include<cstdio>
#include<iostream>
#include<algorithm>
#include<deque>
#include<cctype>
#include<cstdlib>
#include<cstring>
using namespace std;
int read()
{
    char tmp;
    int f(1),x(0);
    for(tmp=getchar();!isdigit(tmp);tmp=getchar()) if(tmp=='-') f=-1;
    for(;isdigit(tmp);tmp=getchar()) x=x*10+tmp-'0';
    return f*x;
}
deque<int> dq;
int tmp,dis[100000],k;
bool visited[100000];
int main()
{
    memset(dis,0x7F,sizeof(dis));
    dis[1]=0; 
    k=read();
    dq.push_back(1);
    while(!dq.empty())
    {
        tmp=dq.front(); dq.pop_front();
        if(tmp==0)
            break;
        if(visited[tmp])
            continue;
        visited[tmp]=true;
        if(dis[(tmp*10)%k]>dis[tmp])
        {
            dis[(tmp*10)%k]=dis[tmp];
            dq.push_front((tmp*10)%k);
        }
        if(dis[(tmp+1)%k]>dis[tmp]+1)
        {
            dis[(tmp+1)%k]=dis[tmp]+1;
            dq.push_back((tmp+1)%k);
        }
    } 
    printf("%d",dis[0]+1);
    return 0;
}