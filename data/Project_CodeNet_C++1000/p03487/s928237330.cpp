#include<bits/stdc++.h>
using namespace std;

int main(){
  unordered_map<int,int> mp;
  set<int> nums;
  int n,num;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> num;
    mp[num]++;
    nums.insert(num);
  }
  
  int res=0;
  for(auto i:nums){
    if(mp[i]==i) continue;
    if(mp[i]>i){
      res += mp[i]-i;
    }
    else{
      res += mp[i];
    }
  }
  cout << res;
  return 0;
}