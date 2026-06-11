#include<bits/stdc++.h>
using namespace std;

int main(){
  long long n,c=0,ans=0;
  string s;
  cin >> n >> s;
  vector<vector<int>>a(n,vector<int>(26));
  vector<int>cnt(26,0);
  for(int i=0;i<s.size();i++){
    a.at(i)=cnt;
    cnt.at(s.at(i)-'a')++;
  }
  for(int i=0;i<s.size();i++){
    long long z=1;
    for(int j=0;j<26;j++)
      if('a'+j!=s.at(i))
      z=(z*(a.at(i).at(j)+1))%1000000007;
    ans=(ans+z)%1000000007;
  }
  cout << ans << endl;
  return 0;
}