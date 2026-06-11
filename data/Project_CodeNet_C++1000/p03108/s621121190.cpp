#include <bits/stdc++.h>
using namespace std;


long long int parent[100005];
long long ans[100005];
long long set_size[100005];


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
        return ;

    }
    else{
        if(set_size[u]>set_size[v])
           swap(u,v);
        parent[u]=v;
        set_size[v]+=set_size[u];
        set_size[u]=1;
    }
}

int main()
{

    long long n,m;
    cin>>n>>m;

    long long f=n*(n-1);
    f=f/2;

    long long a[m],b[m];

    for(int i=1;i<=n;i++)
      makeSet(i);




    for(int i=0;i<m;i++)
        cin>>a[i]>>b[i];


    ans[m]=f;


    for(int i=m-1;i>=0;i--){


         long long k=0;

         long long int z=Find(a[i]);
         long long int x=Find(b[i]),xz;

         if(z!=x){
            z=set_size[z];
            x=set_size[x];

            xz=z+x;
            xz=xz*(xz-1);
            xz=xz/2;


            x=x*(x-1);
            x=x/2;

            z=z*(z-1);
            z=z/2;

            f=f+x+z-xz;



         }

         Union(a[i],b[i]);
         ans[i]=f;


    }

    for(int i=1;i<=m;i++)
        cout<<ans[i]<<endl;









    return 0;
}
