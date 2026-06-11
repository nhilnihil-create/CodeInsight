#include <bits/stdc++.h>
using namespace std;
#define Max 200000

long long int parent[Max],cnt[Max],set_size[Max];


void makeSet(long long int n)
{
    parent[n]=n;
     set_size[n]=1;
}

long long int Find(long long int reprasentative)
{
    if (parent[reprasentative] == reprasentative)
    {
        return reprasentative;
    }
    return parent[reprasentative] = Find(parent[reprasentative]);
}

void Union(long long int a,long long int b)
{
    long long int u = Find(a);
    long long int v = Find(b);
    if(u == v)
    {
        //printf("Frnds");
    }
    else{
        if(set_size[u]>set_size[v])
           swap(u,v);
        parent[u]=v;
        set_size[v]+=set_size[u];
    }
}

long long int paircnt(long long int n)
{
    return (n-1)*n/2;
}

int main()
{
    long long int a,b,c,d,e,f,n,m,i,j,k;
    cin>>n>>m;
    for (int i=0; i <=n; i++)
    {
        makeSet(i);
    }
    c=paircnt(n);
    vector < pair <long long int , long long int > > v1;
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        v1.push_back({a,b});
    }

    vector <long long int> ans;
    ans.push_back(c);
    for(i=m-1;i>0;i--)
    {
        a=v1[i].first;
        b=v1[i].second;
        if(Find(a)==Find(b))
            ans.push_back(c);
        else
        {
            d=set_size[Find(a)];
            e=set_size[Find(b)];
            Union(a,b);
            d=paircnt(d);
            e=paircnt(e);
            c-=(paircnt(set_size[Find(a)])-d-e);
            ans.push_back(c);
        }
    }
    k=ans.size();
    for(i=k-1;i>=0;i--)
    {
        cout<<ans[i];
         cout<<"\n";
    }

    return 0;
}
