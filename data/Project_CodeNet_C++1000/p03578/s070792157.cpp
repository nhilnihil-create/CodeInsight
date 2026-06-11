#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define each(it,v) for(auto &it : v)
#define mod 1000000007
#define All(v) (v).begin(),(v).end()
#define vi vector<int>
#define vl vector<long>
#define P pair<int,int>
#define Graph vector<vector<int>>
using namespace std;

main()
{
        int n;cin>>n;
        map<int,int> dm;
        rep(i,n)
        {
                int d; cin>>d;
                dm[d]++;
        }
        int m; cin>>m;
        bool flag=true;
        rep(i,m)
        {
                int t; cin>>t;
                if(dm[t])
                {
                        dm[t]--;
                }else
                {
                        flag=false;
                }
        }
        cout<<(flag?"YES":"NO")<<endl;
}