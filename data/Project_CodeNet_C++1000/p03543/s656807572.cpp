#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int cnt=0;
  for(int i=0;i<s.size();i++)if(s[i]==s[i+1] && s[i+1]==s[i+2])cnt++;
  if(cnt)cout << "Yes" << endl;
  else cout << "No" << endl;
}