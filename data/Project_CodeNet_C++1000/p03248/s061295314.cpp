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


 main()

{
    fast
    string s;
    cin>>s;
    int sz=s.size();
    if(s[sz-1]=='1' || s[0]=='0')
    {
        cout<<"-1"<<endl;
        return 0;
    }
    int mid=sz/2;
    f(i,0,mid-1)
    {
        int lft=i;
        int rgt=sz-(i+2);
        if(s[lft]!=s[rgt])
        {
            cout<<"-1"<<endl;
            return 0;
        }
    }
    int cur=1;
    int nxt=2;
    int pos=0;
    vector<pi>ses;
    while(pos<mid)
    {
        if(s[pos]=='1')
        {
            ses.pb(mp(cur,nxt));
            cur=nxt;nxt++;
        }
        else
        {
           ses.pb(mp(cur,nxt));
           nxt++;
        }
        pos++;
    }
    f(i,nxt,sz)
    {
        ses.pb(mp(cur,i));
    }
    for(auto x:ses)
    {
        cout<<x.fi<<" "<<x.si<<endl;
    }
    return 0;

}











