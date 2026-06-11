#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e6+3;
const int N=1e6+10;
int n,k;
ll a[1005];
int f[45][1000005];
int b[1000005];
vector<ll>v;
int main(){
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++) scanf("%lld",&a[i]);

    for (int i=1;i<=n;i++)
    {
        ll tmp=0;
        for (int j=i;j<=n;j++)
        {
            tmp+=a[j];
//            c//out<<tmp<<endl;
            v.push_back(tmp);
        }
    }
    for (int i=0;i<v.size();i++)
    {
        for (int j=0;j<42;j++)
        {
            if ((v[i]&((1ll)<<j)))
            {
                f[j][i]=1;
            }
        }
    }
    ll ans=0;
    for (int i=41;i>=0;i--)
    {
        int num=0;
        for (int j=0;j<v.size();j++)
        {
            if (b[j]==0 && f[i][j])
            {
                num++;
            }
        }
        if (num>=k)
        {
            ans+=((1ll)<<i);
            for (int j=0;j<v.size();j++)
            {
                if (b[j]==0 && f[i][j]==0)
                {
                    b[j]=1;
                }
            }
        }
    }

    printf("%lld\n",ans);
}
