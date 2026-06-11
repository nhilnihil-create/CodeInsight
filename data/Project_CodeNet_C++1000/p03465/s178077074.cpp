///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define                           int                         long long
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<int,int>
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




using namespace std;

const int inf=1e18;
const int mod=1e9+7;
const int M=4000009;
inline int bigmod(int B,int P){int R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}

bitset<M>dp;

 main()

{
    fast
    int n;
    int sum=0;
    cin>>n;
    int a[n+4];
    f(i,1,n)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sort(a+1,a+n+1);
    dp.set(0);
    for(int i=1;i<=n;i++)
    {
        dp|=(dp<<a[i]);
    }
    int mid=(sum/2);
    for(int i=mid;i>=0;i--)
    {
        if(dp[i])
        {
            cout<<sum-i<<endl;
            return 0;
        }
    }

}











