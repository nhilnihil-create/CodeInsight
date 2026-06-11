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

int p[MX];

int main()
{

    FasterIO;

    int n, x;

    cin>>n;

    for(int i=1; i<=n; p[x]=i, i++) cin>>x;

    int mx=0, cnt=0, px=0;

    for(int i=1; i<=n; i++)
    {
        if(p[i]>px) cnt++, px=p[i];
        else
        {
            mx=max(mx, cnt); cnt=1, px=p[i];
        }
    }
    mx=max(mx, cnt);

    cout<<n-mx<<endl;

    return 0;
}
