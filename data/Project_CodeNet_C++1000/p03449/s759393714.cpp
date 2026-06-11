#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll x[MAX];
ll y[MAX];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>x[i];
        x[i]+=x[i-1];
    }
    for(int i=1; i<=n; i++)
        cin>>y[i];
    for(int i=n; i>0; i--)
    {
        y[i]+=y[i+1];
    }
    ll ans=0;
    for(int i=1; i<=n; i++)
    {
        ans=max(ans,x[i]+y[i]);
    }
    cout<<ans<<endl;

    return 0;
}
