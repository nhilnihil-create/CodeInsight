///Bismillahir Rahmanir Rahim
#include "bits/stdc++.h"

#define                           ll                          long long
#define                           int                         ll
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<ll,ll>
#define                           node(a,b,c)                 mp(mp(a,b),c)
#define                           clr(x)                      memset(x,0,sizeof(x));
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           show(x,y)                   cout<<x<<" : ";for(auto z:y)cout<<z<<" ";cout<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const ll inf=1e18;
const int mod=1e9+7;
const int M=500005;
int s[M+2],t[M+2],c[M+2];
 main()

{
    fast
    int n,ch,ses=0;
    cin>>n>>ch;
    f(i,1,n)
    {
        cin>>s[i]>>t[i]>>c[i];
    }
    vector<int>tym(M+2,0);
    f(tvc,1,ch)
    {
        vector<int>yo(M+2,0);
        f(i,1,n)
        {
            if(c[i]==tvc)
            {
                yo[s[i]*2-1]++;
                yo[t[i]*2]--;
            }
        }
        f(i,1,M)
        {
            yo[i+1]+=yo[i];
        }
        f(i,1,M)
        {
            tym[i]+=(yo[i]>0);
        }
    }
    f(i,1,M)
    {
       ses=max(ses,tym[i]);
    }
    cout<<ses<<"\n";
    return 0;

}



































