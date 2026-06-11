#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define pf push_front
#define F first
#define S second
#define ll long long
#define f(i) return cout<<i<<"\n",0;
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define lp(i,a,b) for (int i=(a);i<=(int)(b);++i)
#define lp2(i,a,b) for (int i=(a);i>=(b);--i)
#define clr(c,x) memset(c,x,sizeof(c))
#define allr(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
const int N=2e5+5,mod=(int)1e9+7;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,k;
    cin>>n>>k;
    int x=0;
    if (!k)
    {
        lp(i,0,(1<<n)-1) cout<<i<<" "<<i<<" ";
        return 0;
    }
    lp(i,0,(1<<n)-1) if (i!=k)x^=i;
    if (x!=k) f(-1);
    cout<<0<<" "<<k<<" "<<0<<" ";
    lp(i,1,(1<<n)-1)
    {
        if (i!=k)
            cout<<i<<" ";
    }
    cout<<k<<" ";
    lp2(i,(1<<n)-1,1) if (i!=k) cout<<i<<" ";
    return 0;
}