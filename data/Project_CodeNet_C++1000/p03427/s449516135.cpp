#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t n;
  cin >> n;
  if(n<10){
    cout << n << endl;
    return 0;
  }
  string s=to_string(n);
  int ans=s.at(0)-49;
  bool ok=true;
  for(int i=1;i<s.size();i++){
    if(s.at(i)!='9'){
      ok=false;
      break;
    }
  }
  if(ok){
    ans+=(s.size()-1)*9+1;
    cout << ans << endl;
    return 0;
  }   
  ans+=9*(s.size()-1);
  cout << ans << endl;
  return 0;
}
    