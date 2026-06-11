#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll l1[51][51];
ll dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{-1,1},{-1,-1},{1,-1},{1,1}};
map<ll,ll>di;


int main()
{
    ll n,k,m,a,b,s=1;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        s+=min(s,k);
    }
    cout<<s;
}
