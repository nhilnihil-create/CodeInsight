#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll ar[200007],a,b, test, sum,t,x=0,p,q,y,i,j,k=0,l,cnt;
map<ll,ll>br,mp;
void func()
{
    k=0;
    while(k<=34)
    {
        if(k>0)
            mp[++k]=mp[k-1]*2;
        else
            mp[++k]=2;
    }
}
int main()
{
    func();
    ll test;
    cin>>a;
    cnt=0;
    for(i=1; i<=a; i++)
    {
        cin>>ar[i];
        br[ar[i]]++;
    }
    sort(ar+1,ar+a+1);

    for(i=a; i>=1; i--)
    {
        if(br[ar[i]]>=1)
        {
            for(j=k; j>=1; j--)
            {
                ll c=mp[j];
                x=c-ar[i];
                if(x>0)
                if(br[x]==1&&ar[i]!=x||br[x]>1)
                {
                    cnt++;
                    br[ar[i]]--;
                    br[x]--;
                    break;
                }

            }
        }
    }


    printf("%lld\n",cnt);
    return 0;
}
