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

int vis[30009];

 main()

{
    fast
    int n;
    cin>>n;
    int sum=0;
    vector<int>vec;
    int cnt=0;
    for(int i=1;i<=30000;i++)
    {
        if(i%2==0 || i%3==0)
        {
            if(cnt==(n-1))
            {
                break;
            }
            else
            {
                vec.pb(i);
                sum+=i;
                vis[i]=1;
                cnt++;
            }
        }
    }
    for(int i=1;i<=30000;i++)
    {
        if(vis[i])continue;
        int val=sum+i;
        if(__gcd(sum,i)>1 && val%6==0)
        {
            vec.pb(i);
            break;
        }
    }
    for(auto x:vec)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;

}











