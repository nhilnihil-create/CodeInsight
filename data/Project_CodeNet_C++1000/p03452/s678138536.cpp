#include <iostream>
#include <vector>
#define nmax 200010
using namespace std;

int n,m;
bool onr[nmax];
int poz[nmax];
vector< pair<int,int>> g[nmax];

int l[nmax];
int r[nmax];
int d[nmax];

bool viz[nmax];

void solve(int nod)
{
    viz[nod]=1;
    for( pair<int,int> p:g[nod])
    {
        poz[p.first]=poz[nod]+p.second;
        if(!viz[p.first])
            solve(p.first);
    }
}

int main()
{
    int i;
    cin>>n>>m;


    for(i=1;i<=m;i++)
    {
        cin>>l[i]>>r[i]>>d[i];
        onr[r[i]]=1;
        g[l[i]].push_back( make_pair(r[i],d[i]));
    }

    for(i=1;i<=n;i++)
        if(!onr[i])
            solve(i);

  //  for(i=1;i<=n;i++) cout<<poz[i]<<' '; cout<<'\n';

    for(i=1;i<=n;i++)
        if( poz[r[i]]-poz[l[i]]!=d[i])
        {
            cout<<"No\n";
            return 0;
        }
    cout<<"Yes\n";
    return 0;
}
