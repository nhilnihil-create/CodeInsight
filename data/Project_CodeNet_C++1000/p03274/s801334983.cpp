#include<bits/stdc++.h>
using namespace std;
#define int long long int 
int32_t main()
{
    int n,k;
    cin>>n>>k;
    vector<int> neg,pos;
    pos.push_back(0);
    neg.push_back(0);
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x>0)
           pos.push_back(x);
        else
            neg.push_back(-x);     
    }
    sort(neg.begin(),neg.end());
    int ans=INT_MAX;
    for(int i=0;i<=k;i++)
    {
        int m=k-i;
         if(m>=pos.size() ||m<0|| i>=neg.size())
        continue;
        ans=min({ans,pos[m]+2*neg[i],neg[i]+2*pos[m]});
    }
    cout<<ans<<endl;
}