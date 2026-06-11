#include<bits/stdc++.h>
using namespace std;

bool check(int a,int b,int n){
  string s=to_string(n);
  int m=0;
  for(int i=0;i<s.size();i++)
    m+=s.at(i)-48;
  if(a<=m&&b>=m)
    return true;
  return false;
}
int main(){
  int a,b,n;
  cin >> n >>a >> b;
  int ans=0;
  for(int i=1;i<=n;i++){
    if(check(a,b,i))
      ans+=i;
  }
  cout << ans << endl;
}