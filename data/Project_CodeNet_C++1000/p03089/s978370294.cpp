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
inline int ad(int x,int y){int ret=(x%mod+y%mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline int sub(int x,int y){int ret=((x%mod)-(y%mod)+mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline int gun(int x,int y){int ret=((x%mod)*(y%mod))%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}

bool vis[M+4];
int cnt[M+4];
vector<int>ses;
int n;
int b[M+4];
bool chk(int x)
{
    int pos=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            pos++;
            if(pos==x)
            {
                if(b[i]==x)
                {
                    vis[i]=1;
                    ses.pb(x);
                    cnt[x]--;
                    return true;
                }
            }
        }
    }
    return false;
}
 main()

{
    fast
    cin>>n;
    f(i,1,n)
    {
        cin>>b[i];
        cnt[b[i]]++;
    }
    rf(i,n,1)
    {
        int flag=0;
        rf(j,i,1)
        {
            if(cnt[j]>=1){

            if(chk(j))
            {
                flag=1;
                break;
            }

            }
        }
        if(flag==0)
        {
            cout<<"-1"<<endl;
            return 0;
        }
    }
    reverse(ses.begin(),ses.end());
    f(i,1,n)
    {
        if(vis[i]==0)
        {
            cout<<"-1"<<endl;
            //done("hey")
            return 0;
        }
    }
    for(auto x:ses)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;

}



































