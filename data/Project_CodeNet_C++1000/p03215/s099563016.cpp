///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

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

ll inf=1e18;
const int mod=1e9+7;
const int M=1003;
int a[M];
vector<int>vec;
int pre[M];
int sz;
 main()

{
    fast
    int n,k;
    cin>>n>>k;
    int tmp=0;
    vector<int>s;
    f(i,1,n)
    {
        cin>>a[i];
        tmp+=a[i];
        pre[i]=tmp;
    }
    f(i,1,n)
    {
        f(j,i,n)
        {
            int x=pre[j]-pre[i-1];
            vec.pb(x);
        }
    }
    sz=vec.size();
    bitset<42>yo[sz+1];
    f(i,0,sz-1)
    {
        s.pb(i);
        yo[i]=vec[i];
    }
    int ses=0;
    rf(j,40,0)
    {
        vector<int>nw;
        int cnt=0;
        for(auto x:s)
        {
            if(yo[x][j])cnt++,nw.pb(x);
        }
       // cout<<cnt<<"#"<<j<<endl;
        if(cnt>=k)
        {
             s=nw;
             ses+=(1LL<<j);
        }
    }
    cout<<ses<<endl;
    return 0;

}



































