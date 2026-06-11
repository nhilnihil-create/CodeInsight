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
        int n; cin>>n;

        vi v(n);
        each(it,v)cin>>it;

        int cnt=0;
        FOR(i,1,n-1)
        {
                if(v[i-1]==v[i])
                {
                        cnt++;
                        v[i]=100100;
                }
        }
        cout<<cnt<<endl;
}