#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  
  vector<int> cnt(0);
  if(s.at(0) == '0') cnt.push_back(0);
  for(int i = 0; i < n;){
    int j = i;
    while(j + 1 < n && s.at(j) == s.at(j+1)) j++;
    cnt.push_back(j-i+1);
    i = j + 1;
  }
  if(s.at(n-1) == '0') cnt.push_back(0);
  vector<int> sum((int)cnt.size()+1);
  for(int i = 0; i < cnt.size(); i++) sum.at(i+1) = sum.at(i) + cnt.at(i);
  
  int ans = 0;
  for(int i = 0; i < sum.size(); i+=2){
    int j = i + k * 2 + 1;
    if(j >= sum.size()) j = sum.size() - 1;
    ans = max(ans, sum.at(j) - sum.at(i));
  }
  
  cout << ans << endl;
}