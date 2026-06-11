#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  string s;
  cin >> s;
  int ans=1000;
  
  for(int i=0;i<s.size()-2;i++){
    int a;
    a=(s[i]-'0')*100+(s[i+1]-'0')*10+(s[i+2]-'0');
    ans = min(ans,abs(753-a));
  }
   
  
  cout << ans << endl;
  
}
    
    
  
  