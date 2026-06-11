#include <bits/stdc++.h>
using namespace std;
struct node{
  long long int u, v;
    node(long long int _u, long long int _v)
    {
        u = _u;
        v = _v;
    }
};
map <long long int,long long int> parent;
map<long long int, long long int> members;
long long int t,n;
vector <long long> member;
long long int findingRoot(long long int a)
{

    if(parent[a]==a)
    return a;
    else
        return parent[a]= findingRoot(parent[a]);

}
long long lastPar;
void unionSet(long long int a, long long int b)
{
    long long int    A = findingRoot(a);
    long long int  B = findingRoot(b);
    if(A!=B)
    {
         parent[B]=A;

          if(findingRoot(lastPar)!=A )
          {
                 t-=(member[A]*(member[A]-1))/2;
                   t-=(member[B]*(member[B]-1))/2;
                 member[A]+=member[B];
                t+= (member[A]*(member[A]-1)/2);
                lastPar = A;
          }
          else
          {
                   t-=(member[A]*(member[A]-1))/2;
                   t-=(member[B]*(member[B]-1))/2;
                    member[A]+=member[B];
                    member[B]=member[A];
                    t += (member[A]*(member[A]-1)/2);

          }


    }

}
int main()
{
    long long int n, xx, m,x,y;
    cin>>n>>m;
    vector <node> adj;
    while(m--)
    {
        cin>>x>>y;
          parent[x]= x;
            parent[y]= y;
        adj.push_back(node(x,y));
    }
    reverse(adj.begin(),adj.end());
    vector<long long> ans;
    xx = n*(n-1)/2;
    ans.push_back(xx);
    m= adj.size();
    t =0;
    member.resize(n+1,1);
    for(int i=0; i<m; i++)
    {
        long long s1 = adj[i].u, s2 = adj[i].v;
        unionSet(s1,s2);
        ans.push_back(xx-t);
    }

    for(int i=ans.size()-2; i>=0; i--)
        cout<<ans[i]<<endl;
}
