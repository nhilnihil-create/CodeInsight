#include <bits/stdc++.h> 
using namespace std; 

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int ans=0;
    long long m,n,a,b;
    cin>>n>>m;
    vector<pair<long long,long long>>v;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end());
    for(auto x:v)
    {
        if(x.second<=m)
            {ans+=x.first*x.second;m-=x.second;}
        else
            {ans+=x.first*m;m=0;break;}
    }
    cout<<ans<<endl;
    return 0;
}