#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int parent[MAX],tot[MAX];
ll ans[MAX];
int root(int child)
{
    while(parent[child]!=child)
    {
        parent[child]=parent[parent[child]];
        child=parent[child];
    }
    return child;
}
void node_union(int x,int y)
{
    int a=root(x);
    int b=root(y);
    parent[min(a,b)]=parent[max(a,b)];
    tot[max(a,b)]=tot[a]+tot[b];
   // cout<<a<<" "<<b<<" "<<tot[max(a,b)]<<" "<<tot[a]<<" "<<tot[b]<<endl;
}
ll sum(ll x)
{
    return (x*(x+1))/2;
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    for(int i=0; i<=MAX-5; i++)
        parent[i]=i,tot[i]=1;
    vector<pair<int,int> >v;
    int n,m;
    cin>>n>>m;
    ll cur=0;
    for(int i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    cur=sum(n-1);
    ans[m-1]=cur;
    ll rem=0;
    for(int i=m-1; i>0; i--)
    {
        int x=v[i].first;
        int y=v[i].second;
        int a=root(x);
        int b=root(y);
        if(a!=b)
        {
            cur+=sum(tot[a]-1);
            cur+=sum(tot[b]-1);
            node_union(x,y);
            ll temp=tot[root(x)];
            cur-=sum(temp-1);
        }
        ans[i-1]=cur;
    }
    for(int i=0; i<m; i++)
        cout<<ans[i]<<endl;


    return 0;
}
