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
const int M=200009;

inline int bigmod(int B,int P){int R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}
inline int ad(int x,int y){int ret=(x%mod+y%mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline int sub(int x,int y){int ret=((x%mod)-(y%mod)+mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline int gun(int x,int y){int ret=((x%mod)*(y%mod))%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}

int h,w,n;
string s,t;
int p,q;
void bye()
{
    cout<<"NO"<<endl;
    exit(0);
}
void chk_lft()
{
     int x=p,y=q;
     f(i,0,n-1)
     {
         if(s[i]=='L')y--;
         if(y<=0)bye();
         if(t[i]=='R' && y<w)y++;
     }
}
void chk_rgt()
{
     int x=p,y=q;
     f(i,0,n-1)
     {
         if(s[i]=='R')y++;
         if(y>w)bye();
         if(t[i]=='L' && y>1)y--;
     }
}
void chk_up()
{
     int x=p,y=q;
     f(i,0,n-1)
     {
         if(s[i]=='U')x--;
         if(x<=0)bye();
         if(t[i]=='D' && x<h)x++;
     }
}
void chk_down()
{
     int x=p,y=q;
     f(i,0,n-1)
     {
         if(s[i]=='D')x++;
         if(x>h)bye();
         if(t[i]=='U' && x>1)x--;
     }
}
 main()

{
    fast
    cin>>h>>w>>n;
    cin>>p>>q;
    cin>>s>>t;
    chk_lft();
    chk_rgt();
    chk_up();
    chk_down();
    cout<<"YES"<<endl;
    return 0;

}



































