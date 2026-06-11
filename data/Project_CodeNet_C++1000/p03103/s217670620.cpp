
#include <bits/stdc++.h>
#include <vector>


using namespace std;


int main(){

 int n,m;
 cin>>n>>m;

 vector<pair<int, int> >mp(n);


 for(int i=0;i<n;i++){
     cin>>mp[i].first>>mp[i].second;
 }

  sort(mp.begin(),mp.end());

  int64_t ans = 0, i = 0;

 while(m>0){

  ans += (int64_t)mp[i].first * min(mp[i].second,m);
  m -= mp[i].second;
  i++;
 }

 cout<<ans<<endl;

 return 0;
}




