#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m,c,p,q,t,x,d,e,f;
    string s,ss;
    vector<ll>v1;
    deque<ll>dq;
    cin>>n>>m;
    t=x=0;
    ll mn=876476328765;
    for(int i=0;i<n;i++)
    {
        cin>>d>>e;
        if(e<=m)
        {
            mn=min(mn,d);
            x=1;
        }
    }

    if(x==1) cout<<mn<<endl;
    else cout<<"TLE"<<endl;
}





