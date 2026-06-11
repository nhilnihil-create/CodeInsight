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
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    ll n,k,ans=9e18;
    cin>>n>>k;
    vector<ll>a(n),b(n),x,y;
    for(int i=0; i<n; i++)
    {
        cin>>a[i]>>b[i];
        x.push_back(a[i]);
        y.push_back(b[i]);
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    for(int x1=0; x1<n; x1++)
    {
        for(int x2=x1+1; x2<n; x2++)
        {
            for(int y1=0; y1<n; y1++)
            {
                for(int y2=y1+1; y2<n; y2++)
                {
                    ll cnt=0;
                    ll lx=x[x1],rx=x[x2];
                    ll ly=y[y1],ry=y[y2];
                    for(int i=0; i<n; i++)
                    {
                        if(a[i]>=lx && a[i]<=rx && b[i]>=ly && b[i]<=ry)
                            cnt++;
                    }
                    if(cnt>=k){
                        ans=min(ans,(rx-lx)*(ry-ly));
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
