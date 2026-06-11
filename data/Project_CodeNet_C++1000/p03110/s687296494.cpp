#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  double x,ans=0;
  string s;
  for(int i=0;i<n;i++){
    cin >> x >> s;
    if(s=="JPY")
      ans+=x;
    else
      ans+=x*380000;
  }
  cout << ans << endl;
  return 0;
}