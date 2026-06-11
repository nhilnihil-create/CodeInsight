#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k; cin >> n >> k;
  string s; cin >> s;
  vector<int> seq;
  if(s[0] == '0') seq.push_back(0);
  for(int i = 0; i < s.size();){
    int j = i;
    while(j < s.size() && s[j] == s[i]) j++;
    seq.push_back(j-i);
    i = j;
  }
  if(s.back() == '0') seq.push_back(0);
  vector<int> sum((int)seq.size()+1, 0);
  for(int i = 0; i < seq.size(); i++){
    sum[i+1] = sum[i] + seq[i];
  }
  int ans = 0;
  for(int i = 0; i < sum.size(); i += 2){
    int tmp = i + 2*k + 1;
    if(tmp >= sum.size()) tmp = sum.size() - 1;
    ans = max(ans, sum[tmp] - sum[i]);
  }
  cout << ans << endl;
}

