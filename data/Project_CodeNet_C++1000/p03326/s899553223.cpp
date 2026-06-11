/*Remember: The Struggle is Important*/

//CF,CC,AtC,SPOJ: hp1999
//HE: hemant269
//HR: hemant2132

#include<bits/stdc++.h>
using namespace std;

#define     int          long long int
#define     ld           long double
#define     fast()       ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define     all(x)       x.begin(),x.end()
#define     mem(a,b)     memset(a,b,sizeof(a))
#define     gcd(a,b)     (__gcd((a),(b)))
#define     lcm(a,b)     (((a)*(b))/gcd((a),(b)))
#define     pb           push_back
#define     ins          insert
#define     pii          pair<int,int>
#define     F            first
#define     S            second
#define     makep        make_pair
#define     maket        make_tuple
#define     show(x)      for(auto c:x)cout<<c<<" ";cout<<"\n";
#define     show2(x)     for(auto c:x)cout<<c.F<<" "<<c.S<<"\n";

const int inf=1e18,M=1e9+7;
const int N=1;

void solve()
{
    int n,m;
    cin>>n>>m;

    int v[n][3];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<3;++j)
            cin>>v[i][j];
    }

    vector<int> vec;
    int ans=0;
    for(int k=0;k<8;++k)
    {
        vec.clear();

        for(int i=0;i<n;++i)
        {
            int sum=0;
            for(int j=0;j<3;++j)
            {
                if(k&(1<<j))
                    sum+=v[i][j];
                else
                    sum-=v[i][j];
            }

            vec.pb(sum);
        }

        sort(all(vec));
        reverse(all(vec));

        //show(vec);

        ans=max(ans,accumulate(vec.begin(),vec.begin()+m,0ll));
    }

    cout<<ans;
}

int32_t main()
{
    fast();

    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
        //cout<<"\n";
    }

    return 0;
}


