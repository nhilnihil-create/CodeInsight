#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
void dfs(long long x){
  if(n<x) return;
  string s=to_string(x);
  if(count(s.begin(),s.end(),'3') && count(s.begin(),s.end(),'5') && count(s.begin(),s.end(),'7')){
    ans ++;
  }
  dfs(10*x+3);
  dfs(10*x+5);
  dfs(10*x+7);
  return;
}

int main(){
  cin >> n;
  dfs(0);
  cout << ans << endl;
}
