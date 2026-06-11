#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using product = pair<ll,ll>;
using vvll = vector<vector<ll>>;
using vll = vector<ll>;
 
ll H,W;
vvll route;
vvll dist;
 
bool checkRoute(ll x,ll y)
{
    if(x<0 || y<0 || H-1<x || W-1<y)return false;
    if(dist[x][y]==-1 && route[x][y]==1)return true;
    return false;
}
 
int main(){
    ll black=0;
    cin>>H>>W;
    route.resize(H);
    dist.resize(H);
    for(ll i=0;i<H;i++)
    {
        route[i]=vll(W,0);
        dist[i]=vll(W,-1);
        for(ll j=0;j<W;j++)
        {
            char s;cin>>s;
            if(s=='.'){
                route[i][j]=1;
            }
            else {
                route[i][j]=0;black+=1;
            }
        }
    }
    queue<product>  que;
    que.push(make_pair(0,0));
    dist[0][0]=0;
    while(!que.empty())
    {
        product v=que.front();
        que.pop();
 
        if(checkRoute(v.first+1,v.second))
        {
            que.push(make_pair(v.first+1,v.second));
            dist[v.first+1][v.second]=dist[v.first][v.second]+1;
        }
        if(checkRoute(v.first-1,v.second))
        {
            que.push(make_pair(v.first-1,v.second));
            dist[v.first-1][v.second]=dist[v.first][v.second]+1;
        }
        if(checkRoute(v.first,v.second+1))
        {
            que.push(make_pair(v.first,v.second+1));
            dist[v.first][v.second+1]=dist[v.first][v.second]+1;
        }
        if(checkRoute(v.first,v.second-1))
        {
            que.push(make_pair(v.first,v.second-1));
            dist[v.first][v.second-1]=dist[v.first][v.second]+1;
        }
    }
    if(dist[H-1][W-1]==-1)cout<<-1<<endl;
    else cout<<H*W-(dist[H-1][W-1]+1)-black<<endl;
    return 0;
}