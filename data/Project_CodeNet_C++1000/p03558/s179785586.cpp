#include<iostream>
using namespace std;
int n;
const int sz=1e5;
bool vis[sz][100];
int suma(int n)
{
    int res=0;
    while(n>0)
    {
        res+=n%10;
        n/=10;
    }
    return res;
}
void dfs(int r,int s)
{
    if(s>=99)return;
    if(vis[r][s])return;
    vis[r][s]=1;
    for(int i=0;i<10;i++)dfs((10*r+i)%n,s+i);
}
main()
{
    cin>>n;
    for(int i=0;i<n;i++)dfs(i,suma(i));
    int res=1e9;
    for(int i=1;i<99;i++)if(vis[0][i])res=min(res,i);
    cout<<res<<endl;
    return 0;
}