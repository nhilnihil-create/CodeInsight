#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,a,b) for(int i=a;i<b;i++)
#define each(it,v) for(auto it : v)
#define mod 1000000007
#define all(v) (v).begin(),(v).end()
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pair<int,int>>
#define vv vector<vector<int>>
using namespace std;

main()
{
    int n,c; cin>>n>>c;
    vv v;
    int s,t,a;
    rep(i,n)
    {
        cin>>s>>t>>a;
        v.push_back({s,t,a});
    }

    vi imos(200200,0);
    rep2(t,1,c+1)
    {
        vi cc(200200,0);
        rep(i,n)
        {
            if(v[i][2]==t)
            {
                cc[2*v[i][0]-1]++;
                cc[2*v[i][1]]--;
            }
        }
        rep2(i,1,cc.size())cc[i]+=cc[i-1];
        //each(it,cc)cout<<it;
        //cout<<endl;
        rep(i,cc.size())
        {
            if(cc[i]>0)imos[i]++;
        }
    }

    //each(it,imos)cout<<it;
    //cout<<endl;

    int mx=0;
    each(it,imos)mx=max(mx,it);
    cout<<mx<<endl;

}