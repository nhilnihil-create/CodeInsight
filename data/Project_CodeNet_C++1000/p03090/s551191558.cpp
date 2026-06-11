#include<bits/stdc++.h>
using namespace std;
#define FasterIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define ff first
#define ss second
#define mk make_pair
#define pi pair<int,int>
#define vi vector<int>
#define pL pair<ll,ll>
#define vL vector<ll>
#define vp vector<pi>
#define vpL vector<pL>

const int MX=1000000;
const ll inf=1e9;
const ll mod=998244353;


vector<pi>edge;

int n;

void solve(int d)
{
    for(int u=n; u>=1; u--)
    {
        for(int v=u-1; v>=1; v--)
        {
            if(u+v!=d)
            {
                edge.push_back({u, v});
            }
        }
    }
}

int main()
{

    FasterIO;

    cin>>n;

    int d=n*(n-1); d/=2;

    int x=n*(n+1); x/=2;

    if(n&1) solve(x-d);
    else    solve(x-d+1);

    cout<<edge.size()<<endl;
    for(auto pr:edge) cout<<pr.ff<<' '<<pr.ss<<endl;

    return 0;
}
