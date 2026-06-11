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
        int a,b,c; cin>>a>>b>>c;
        int cnt;
        if(a+b>=c)cnt=b+c;
        else if(a+b+1==c)cnt=b+c;
        else cnt=b*2+a+1;
        cout<<cnt<<endl;
}
