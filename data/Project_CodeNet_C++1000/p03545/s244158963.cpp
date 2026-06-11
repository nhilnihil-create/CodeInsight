#include <bits/stdc++.h>
using namespace std;

bool ok = false;

void dfs(int nums[], int len, int opes[], int sum){
  if(ok)  return;
  if(len == 3){
    if(sum == 7){
      string s; s += (char)(nums[0]+'0');
      for(int i=1; i<4; i++){
	string o;
	if(opes[i-1] == 1)  o = "+";
	else  o = "-";
	s = s + o + (char)(nums[i]+'0');
      }
      s += "=7";
      cout << s << endl;
      ok = true;
    }
    return;
  }
  opes[len] = 1;
  dfs(nums, len+1, opes, sum+nums[len+1]);
  opes[len] = -1;
  dfs(nums, len+1, opes, sum-nums[len+1]);
  opes[len] = 0;
}

int main(){
  string s;  cin >> s;
  int nums[4], opes[4] = {0};
  for(int i=0; i<4; i++)
    nums[i] = (int)(s[i]-'0');
  dfs(nums, 0, opes, nums[0]);
    
  return 0;
}
