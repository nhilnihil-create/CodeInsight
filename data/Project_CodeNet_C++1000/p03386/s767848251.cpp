#include <bits/stdc++.h>
using namespace std;

bool check(int n,vector<int>&ans){
  for(int i=0;i<ans.size();i++)
    if(ans.at(i)==n)
      return false;
  return true;
}
  
int main(){
  int a,b,k;
  cin >> a >> b >> k;
  vector<int>ans;
  for(int i=0;i<k;i++)
    if(a+i<=b)
      ans.push_back(a+i);
  for(int i=0;i<k;i++)
    if(b-i>=a&&check(b-i,ans))
      ans.push_back(b-i);
  sort(ans.begin(),ans.end());
  for(int i=0;i<ans.size();i++)
    cout << ans.at(i) << endl;
  return 0;
}