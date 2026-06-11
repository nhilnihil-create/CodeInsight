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
const int M=100009;
inline int bigmod(int B,int P){int R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}

int a[M+7];
int n;

 main()

{
    fast
    cin>>n;
    f(i,1,n)
    {
        cin>>a[i];
    }
    reverse(a+1,a+n+1);
    int pl=2,pr=2,l,r;
    f(i,1,n)
    {
        int ymx=(pr/a[i])*a[i];
        int ymn=((pl+a[i]-1)/a[i])*a[i];
        if(!(ymx>=pl && ymx<=pr) || !(ymn>=pl && ymn<=pr))
        {
            cout<<"-1"<<endl;
            return  0;
        }
        l=ymn;
        r=ymx+a[i]-1;
        pl=l;
        pr=r;
    }
    cout<<l<<" "<<r<<endl;
    return 0;

}











