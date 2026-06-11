#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  int cnt0=0,cnt1=0;
  for(int i=0;i<s.size();i++){
    if(s[i]=='0') cnt0++;
    else cnt1++;
  }
  cout<<2*min(cnt0,cnt1);
}