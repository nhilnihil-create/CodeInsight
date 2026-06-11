#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  long long k=0;
  long long ans=0;
  
  for(int i=0;i<s.size();i++){
    if(s.at(i)=='B') k++;
    else ans+=k;
  }
  
  cout << ans << endl;
  
}