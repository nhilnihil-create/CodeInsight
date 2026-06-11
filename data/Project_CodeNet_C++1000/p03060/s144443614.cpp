#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t,i,n,x,y;
    ll ans=0;
    cin>>n;
    vector<ll>k(n),l(n);
    for(i=0;i<n;i++)
    {
        cin>>x;
        k.push_back(x);
    }
    for(i=0;i<n;i++){
        cin>>y;
        l.push_back(y);

    }
    for(i=0; i<k.size(); i++)
    {
        if(k.at(i)>l.at(i))
        {
            ans+=k.at(i)-l.at(i);
        }
    }

    cout<<ans<<endl;



    return 0;
}


