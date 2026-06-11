#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n,m;
int p[100010];
vector<int> graf[100010];
int mark[100010];
int flag=1;

void bfs(int c)
{
    if(mark[c]==0)
        mark[c]=flag;
    else
        return;
    for(int i=0;i<graf[c].size();i++)
        if(mark[graf[c][i]]==0)
            bfs(graf[c][i]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    int x,y;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        graf[x].push_back(y);
        graf[y].push_back(x);
    }

    int sol=0;
    for(int i=1;i<=n;i++)
    {
        if(mark[i]==0)
            bfs(i), flag++;
    }
    for(int i=1;i<=n;i++)
        if(mark[p[i]]==mark[i])
            sol++;
    cout<<sol;
	return 0;
}
