///Bismillahir Rahmanir Rahim
#include "bits/stdc++.h"

#define                           ll                          long long
#define                           int                         ll
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<ll,ll>
#define                           clr(x)                      memset(x,0,sizeof(x));
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           show(x,y)                   cout<<x<<" : ";for(auto z:y)cout<<z<<" ";cout<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const ll inf=1e18;
const int mod=1e9+7;
const int M=200005;
int a[M],pre[M];
inline int rsum(int l,int r)
{
    return (pre[r]-pre[l-1]);
}
inline int maxi(int a,int b,int c,int d)
{
    return max(max(a,b),max(c,d));
}
inline int mini(int a,int b,int c,int d)
{
    return min(min(a,b),min(c,d));
}
 main()

{
    fast
    int n,sum=0;
    cin>>n;
    f(i,1,n)
    {
        cin>>a[i];
        sum+=a[i];
        pre[i]=sum;
    }
    int l=1,r=3,ses=inf;
    f(i,2,n)
    {
        while(l+2<=i && abs(rsum(1,l)-rsum(l+1,i)) > abs(rsum(1,l+1)-rsum(l+2,i)))l++;
        while(r+2<=n && abs(rsum(i+1,r)-rsum(r+1,n)) > abs(rsum(i+1,r+1)-rsum(r+2,n)))r++;
        int a=rsum(1,l),b=rsum(l+1,i),c=rsum(i+1,r),d=rsum(r+1,n);
        ses=min(ses,maxi(a,b,c,d)-mini(a,b,c,d));
    }
    cout<<ses<<endl;
    return 0;

}



































