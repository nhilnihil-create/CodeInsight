#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define each(it,v) for(auto &it : v)
#define All(v) (v).begin(),(v).end()
#define vi vector<int>
#define vl vector<long>
#define P pair<int,int>
#define Graph vector<vector<int>>
using namespace std;

main()
{
        int n,m; cin>>n>>m;

        vl a(n);
        rep(i,n)cin>>a[i];

        vl wa(n+1,0);
        rep(i,n)wa[i+1]=wa[i]+a[i];

        vl mod(n+1);
        rep(i,n+1)mod[i]=wa[i]%m;

        map<long,long> M;
        rep(i,n+1)M[mod[i]]++;
        
        long ans=0;
        each(it,M)ans+=it.second*(it.second-1)/2;
        cout<<ans<<endl;
}