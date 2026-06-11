#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define lc (rt<<1)
#define rc (rt<<1|1)
#define mp make_pair
#define pb push_back
#define lowbit(a) (a&(-a))
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
#define mst(a,v) memset(a,v,sizeof(a))
#define IOS {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

const int N=100010;
const int mod=1e9+7;
const ld PI=acos(-1.0);
const int inf=0x3f3f3f3f;
const ll INF=1e18;

int n,t;
vi ans[N];

int main()
{
    IOS
    cin>>n;
    int k=sqrt(2*n);
    if(k*(k+1)!=2*n) return cout<<"No",0;
    cout<<"Yes"<<'\n'<<k+1<<endl;
    for(int i=1; i<=k+1; i++)
        for(int j=i+1; j<=k+1; j++)
        ans[i].pb(++t),ans[j].pb(t);
    for(int i=1; i<=k+1; i++)
    {
        cout<<k;
        for(auto x: ans[i]) cout<<' '<<x;
        cout<<endl;
    }
    return 0;
}
