#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e5+10;

struct edge {int u,v,w;};
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int L;
    cin>>L;
    int n=1;
    while ((1<<(n-1))<=L) n++;
    n--;
    vector<edge> ans;
    for (int i=1;i<n;i++)
    {
        ans.pb({i,i+1,0});
        ans.pb({i,i+1,1<<(n-i-1)});
    }
    int w=(1<<(n-1));
    for (int i=n-2;i>=0;i--)
        if ((L>>i)&1)
        {
            ans.pb({1,n-i,w});
            w+=(1<<i);
        }
    cout<<n<<" "<<ans.size()<<"\n";
    for (edge x : ans) cout<<x.u<<" "<<x.v<<" "<<x.w<<"\n";
    return 0;
}
