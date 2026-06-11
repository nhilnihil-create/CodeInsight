#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,m;cin>>n>>m;

    vector<pair<int,int>> p(m);
    for(int i=0;i<m;i++)
    {
        int ip,iy;cin>>ip>>iy;
        p[i]=make_pair(ip,iy);
    }

    vector<vector<pair<int,int>*>> v(n);
    for(int i=0;i<m;i++)v[p[i].fi-1].push_back(&p[i]);

    for(int i=0;i<n;i++)
    {
        if(v[i].size()==0)continue;
        sort(v[i].begin(),v[i].end(),[](pair<int,int>* l, pair<int,int>* r){return l->se<r->se;});
        for(int j=0;j<v[i].size();j++)v[i][j]->se=j+1;
    }

    for(int i=0;i<m;i++) printf("%06d%06d\n",p[i].fi,p[i].se);

    return 0;
}
