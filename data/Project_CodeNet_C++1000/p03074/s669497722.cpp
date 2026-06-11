#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n,k;
  cin >> n >> k;
  
  string s;
  cin >> s;
  
  vector<int>nums;
  int now = 1;
  int count = 0;
  for(int i=0; i<n; i++){
    if(s[i]==('0'+now))  count++;
    else{
      nums.push_back(count);
      now = 1-now;
      count = 1;
    }
  }
    if(count != 0) nums.push_back(count);
    if(nums.size()%2==0)nums.push_back(0);
    
    int add = 2*k+1;
    
    vector<int>sum(nums.size()+1);
    for(int i=0; i<nums.size(); i++){
     sum[i+1]=sum[i]+nums[i];
    }
    
    int ans =0;
    
    for(int i=0; i<nums.size(); i+=2){
     int left = i;
      int right = min(i+add,(int)nums.size());
      int tmp = sum[right]-sum[left];
      ans = max(tmp,ans);
    }
  
    
    cout << ans << endl;
    
    return 0;
  
}