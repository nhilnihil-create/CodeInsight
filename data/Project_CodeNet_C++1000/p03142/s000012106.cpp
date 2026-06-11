#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> dsk[100005];
int bac[100005];
int parent[100005];
void nhap()
{
    cin>>n>>k;
    for (int i=1;i<=n-1+k;i++)
    {
        int x,y;cin>>x>>y;
        dsk[x].push_back(y);
        bac[y]++;
//        cout<<x<<' '<<y<<endl;
    }
}
void bfs(int x)
{
    queue<int> st;
    st.push(x);
    while (!st.empty())
    {
        int u=st.front();
        st.pop();
        for (int v:dsk[u])
        {
            bac[v]--;
            if (!bac[v])
            {
                parent[v]=u;
                st.push(v);
            }
        }
    }
}
void xuli()
{
    for (int i=1;i<=n;i++)
    if (!bac[i])
    {
        bfs(i);
        break;
    }
    for (int i=1;i<=n;i++) cout<<parent[i]<<"\n";
}
int main()
{
   // freopen("Restorethetree.inp","r",stdin);
   // freopen("Restorethetree.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    nhap();
    xuli();
}
