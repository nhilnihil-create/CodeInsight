#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  reverse(s.begin(),s.end());
  
  int k=0;
  long long ans=0;
  
  for(int i=0;i<s.size();i++){
    if(s.at(i)=='B'){
      ans+=i-k;
      k++;
    }
  }
  
  cout << ans << endl;
  
}