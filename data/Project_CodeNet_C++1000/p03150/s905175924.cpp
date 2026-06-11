#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s="keyence";
  string t;
  cin>>t;
  int n=t.size();
  for(int i=0;i<8;i++){
    string a,b;
    a=t.substr(0,7-i);
    b=t.substr(n-i,i);
    if(a==s.substr(0,7-i)&&b==s.substr(7-i,i)){
      cout<<"YES"<<endl;
      return 0;
    }
    //cout<<a<<b<< " "<<s.substr(0,7-i)<<" "<<s.substr(7-i,i)<<endl;
  }
  cout<<"NO"<<endl;
  return 0;
}