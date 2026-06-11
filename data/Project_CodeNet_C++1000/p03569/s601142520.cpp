#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;


int main(void){
  int n,m,i,x;
  string s,t="";
  vector<int> wx;
  
  cin >> s;
  n=s.size();
  
  i=0;
  while (i<n){
    x=0;
    while (i<n && s[i]=='x'){
      i++;
      x++;
    }
    wx.push_back(x);
    if (i<n) t+=s[i];
    i++;
  }
  if (s[i]!='x') wx.push_back(0);
  
  m=t.size();
  for (i=0;i<m;i++){
    if (t[i]!=t[m-i-1]){
      cout << -1 << endl;
      return 0;
    }
  }
  
  int ans=0;
  for (i=0;i<m+1;i++){
    ans+=abs(wx[i]-wx[m-i]);
    wx[i]=max(wx[i],wx[m-i]);
    wx[m-i]=max(wx[i],wx[m-i]);
  }
  
  cout << ans << endl;
  
  return 0;
}