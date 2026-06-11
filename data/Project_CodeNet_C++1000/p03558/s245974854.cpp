#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<deque>
using namespace std;
#define ll long long
#define rg register
#define inf 0x3f3f3f3f
#define MX 100005
#define fi first
#define se second
typedef pair<int,int> PA;
deque<PA> que;
int dis[MX];
int n;
int main(){

    scanf("%d",&n);
    memset(dis,inf,sizeof(dis));
    que.push_front(make_pair(1,1));
    while(1)
    {
        PA x=que.front();que.pop_front();
        if(dis[x.fi]<=x.se) continue;
        else dis[x.fi]=x.se;
        if(x.fi==0) break;
        if(x.fi%10!=9) que.push_back(make_pair(x.fi==n-1?0:x.fi+1,x.se+1));
        que.push_front(make_pair(x.fi*10%n,x.se));
    }
    printf("%d\n",dis[0]);
    return 0;
}