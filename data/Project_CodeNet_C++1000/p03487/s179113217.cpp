#include <bits/stdc++.h>
#include <vector>


using namespace std;
int main(){

 long long n,x;
 map<long long,long long>mp;

 cin>>n;

 for(long long  i=0;i<n;i++){
        cin>>x;
    mp[x]++;
 }

 int j=0,ans=0;
 for(map<long long,long long >::iterator it = mp.begin();it!= mp.end();it++)
 {
    if(it->first != it->second &&  it->second > it->first)
        ans += abs(it->second - it->first);
    else if(it->second < it->first)
        ans += it->second;
 }

 cout<<ans<<endl;

return 0;
}

