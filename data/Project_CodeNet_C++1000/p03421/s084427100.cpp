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
const int M=100005;

 main()

{
    fast
    int n,a,b;
    cin>>n>>a>>b;
    if(n<a+b-1 || n>a*b)
    {
        cout<<"-1"<<endl;return 0;
    }
    int cur=1;
    vector<vector<int> >vec;
    while(1)
    {
        int lft=cur;
        int rgt=cur+a-1;
        vector<int>nw;
        rgt=min(rgt,n);
        f(i,lft,rgt)nw.pb(i);
        vec.pb(nw);
        cur=rgt+1;
        if(cur>n)break;
    }
    int sz=vec.size();
    vector<vector<int> >ses;
    rf(i,sz-1,0)
    {
        int dan=i;
        int nd=b-dan;
        if(nd==1)
        {
            ses.pb(vec[i]);
            b--;
            continue;
        }
        int len=vec[i].size();
        vector<int>nw;
         if(nd>=len)
        {
             nw=vec[i];
             reverse(nw.begin(),nw.end());
             ses.pb(nw);
             b=b-len;
        }
        else
        {

           f(j,0,nd-1)
           {
               nw.pb(vec[i][j]);
           }
           reverse(nw.begin(),nw.end());
           f(j,nd,len-1)
           {
               nw.pb(vec[i][j]);
           }
           ses.pb(nw);
           b-=nd;
        }
    }
    for(auto x:ses)
    {
        for(auto z:x)
        {
            cout<<z<<" ";
        }
    }
    cout<<endl;
    return 0;

}



































