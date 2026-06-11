#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define each(it,v) for(auto &it : v)
#define all(v) (v).begin(),(v).end()
#define mod 1e9+7

using namespace std;
using vi = vector<int>;
using vl = vector<long>;
using P = pair<int,int>;

main()
{
        vi v(4);
        rep(i,4)cin>>v[i];
        sort(all(v));
        bool flag=false;
        if(v[0]==1)if(v[1]==4)if(v[2]==7)if(v[3]==9)flag=true;
        cout<<(flag?"YES":"NO")<<endl;
}