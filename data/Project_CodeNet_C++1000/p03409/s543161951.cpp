#include<bits/stdc++.h>
using namespace std;
#define int long long int 

int32_t main()
{
    int n;
    cin>>n;
     vector<pair<int,int>> red(n),blue(n);
     for(int i=0;i<n;i++) cin>>red[i].second>>red[i].first;
     for(int i=0;i<n;i++) cin>>blue[i].first>>blue[i].second;
     sort(red.begin(),red.end());
     sort(blue.begin(),blue.end());
     int ans=0;
     for(int i=0;i<n;i++)
     {
         for(int j=n-1;j>=0;j--)
         {
             if(!(blue[i].first>red[j].second && blue[i].second>red[j].first))continue;
             ans++;
             red[j].first=INT_MAX;
             red[j].second=INT_MAX;
             break;
         }
     }
     cout<<ans<<endl;

}