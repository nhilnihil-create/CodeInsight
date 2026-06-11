//by sdfzchy
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
const int inf=(1<<30),N=100010;
int n,m;
deque<PII> q;
inline int in()
{
    char ch=getchar();
    int f=1,tmp=0;
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') {tmp=(tmp<<1)+(tmp<<3)+(ch-'0');ch=getchar();}
    return tmp*f;
}
bool vis[N];
int main()
{
    n=in();
    q.push_front(make_pair(1,1));
    while(!q.empty())
    {
        PII x=q.front();
        q.pop_front();
        int fir=x.first,sec=x.second;
        if(vis[fir]) continue;
        vis[fir]=1;
        if(fir==0) {printf("%d\n",sec);return 0;}
        q.push_front(make_pair(fir*10%n,sec));
        q.push_back(make_pair((fir+1)%n,sec+1));
    }
    return 0;
}
