#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
#define MAXN 0x3f3f3f3f
ll a[1005];
ll s[500501];
ll ss[41];
ll kkk[41];
int n,k;
vector<ll> K,S;
int pp=40;
void solve(int pos)
{
    for(int p=pos-1;p>=0;p--)
    {
        int ppp=0;
        for(int i=0;i<K.size();i++)
        {
            if(K[i]>>p&1)
                ppp++;
        }
        if(ppp>=k)
        {
            pp=p;
            kkk[pp]=1;
            break;
        }
    }
    //cout<<pos<<"**"<<pp<<endl;
    if(pos==pp)
        return;
    for(int i=0;i<K.size();i++)
    {
        if(K[i]>>pp&1)
            S.push_back(K[i]);
    }
    K=S;
    S.clear();
    solve(pp);
}
int main()
{
    
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    int po=0;
    for(int i=0;i<n;i++)
    {
        ll sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=a[j];
            K.push_back(sum);
        }
    }
    solve(41);
    ll ssss=1,ans;
    for(int i=0;i<=40;i++)
    {
        if(kkk[i]==1)
            ans+=ssss;
        ssss*=2;
    }
    printf("%lld\n",ans);
    return 0;
}

