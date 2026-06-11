#include <iostream>
#include <vector>
#define nmax 200005
using namespace std;
int n, nod1, viz1[nmax], viz2[nmax], maxi1, maxi2, nod2;
vector <int> v[nmax];
void dfs1(int nod)
{
    for(auto it=v[nod].begin(); it!=v[nod].end(); ++it)
        if(!viz1[*it])
          {
              viz1[*(it)]=viz1[nod]+1;
              if(maxi1< (viz1[*(it)])) {nod1=*(it); maxi1=viz1[*(it)];}
              dfs1(*it);
          }
}
void dfs2(int nod)
{
    for(auto it=v[nod].begin(); it!=v[nod].end(); ++it)
        if(!viz2[*it])
          {
              viz2[*(it)]=viz2[nod]+1;
              if(maxi2< (viz2[*(it)])) {nod2=*(it); maxi2=viz2[*(it)];}
              dfs2(*it);
          }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, x, y;
    cin>>n;
    for(i=1; i<n; i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    maxi1=1;
    nod1=1;
    viz1[1]=1;
    dfs1(1);

    viz2[nod1]=1;
    maxi2=1;
    dfs2(nod1);

    if(maxi2%3==2) cout<<"Second\n";
    else cout<<"First\n";
    return 0;
}