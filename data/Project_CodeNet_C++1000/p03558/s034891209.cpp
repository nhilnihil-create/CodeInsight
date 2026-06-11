#include<bits/stdc++.h>
using namespace std;
int k,l=1,r=1,a1,a2;
bool vis[100005];
typedef pair<int, int> P;
deque<P> que;
int main()
{
    scanf("%d",&k);que.push_back(make_pair(1, 1));
    while(!que.empty())
    {
        P x=que.front();que.pop_front();
        if(vis[x.first]) continue;vis[x.first]=1;
        if(x.first==0){printf("%d",x.second);return 0;}
        que.push_front(make_pair(x.first*10 % k,x.second));
        que.push_back(make_pair((x.first+1)%k,x.second+1));
    }
    return 0;
}