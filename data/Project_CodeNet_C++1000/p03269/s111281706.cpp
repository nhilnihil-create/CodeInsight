#include<bits/stdc++.h>
using namespace std;
int L;
struct ii
{
    int x,y,w;
};
vector<ii> st;
bool get(int x,int k)
{
    return (x>>(k-1))&1;
}
void xuli()
{
    int t=1,n=1;
    while (t*2<=L)
    {
        st.push_back({n,n+1,0});
        st.push_back({n,n+1,t});
        t*=2;n++;
    }
    int res=L-t;
    for (int i=n-1;i>=1;i--)
    {
        if (get(res,i))
        {
            st.push_back({i,n,t});
            t=t+(res&(1<<(i-1)));
        }
    }
    cout<<n<<' '<<st.size()<<"\n";
    for (ii u:st)
    {
        cout<<u.x<<' '<<u.y<<' '<<u.w<<"\n";
    }
}
int main()
{
    //freopen("allyourpatharedifferentlength.inp","r",stdin);
   // freopen("allyourpatharedifferentlength.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>L;
    xuli();
}
