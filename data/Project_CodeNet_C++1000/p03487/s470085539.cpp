#include <iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#define ll long long
using namespace std;
int main(void){
    // Your code here!
ll n,ans=0;
cin>>n;
map<ll,ll> mp;
for(int i=0;i<n;i++){
    ll a;
    cin>>a;
    mp[a]++;
   // cout<<mp[a]<<endl;
}

for(auto it=mp.begin();it!=mp.end();it++){
   // cout<<it->first<<" "<<it->second<<endl;
    if(it->first > it->second)
        ans+=it->second;
    else{
        ans+=(it->second- it->first);
    }
}
    
cout<<ans;    
}
