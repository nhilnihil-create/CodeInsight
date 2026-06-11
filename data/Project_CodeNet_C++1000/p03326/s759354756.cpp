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
#define F first
#define S second
ll x[2000],y[2000],z[2000],ans,n,m;
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        cin>>x[i]>>y[i]>>z[i];
    }
    for(int i=-1; i<=1; i++)
    {
        for(int j=-1; j<=1; j++)
        {
            for(int k=-1; k<=1; k++)
            {
                vector<ll>v;
                for(int l=0;l<n;l++)
                    v.push_back(x[l]*i+y[l]*j+z[l]*k);
                sort(v.begin(),v.end());
                ll sum=0;
                for(int l=n-1,p=m;p>0;p--,l--)
                    sum+=v[l];
                ans=max(ans,sum);

            }
        }
    }
    cout<<ans<<endl;


    return 0;
}
