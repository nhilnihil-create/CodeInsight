#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(n);i++)
int main()
{
    int n,m,ans=0;
    cin>>n>>m;
    if(n>=m) 
    {
        cout<<"0";
        return 0;
    }
    vector<int> x(m),data(m-1);
    rep(i,m) cin>>x[i];
    sort(x.begin(),x.end());
    rep(i,m-1) data[i]=x[i+1]-x[i];
    sort(data.begin(),data.end());
    int num=m-n;
    rep(i,num) ans+=data[i];
    cout<<ans;
}