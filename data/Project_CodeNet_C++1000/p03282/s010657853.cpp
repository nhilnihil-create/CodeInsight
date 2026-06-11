#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  int k,i=0;
  cin >> s >> k;
  k--;
  while(i<s.size()&&s.at(i)=='1')
    i++;
  //cout << i << '/';
  if(i>k)
    cout << 1 << endl;
  else
    cout << s.at(i) << endl;
  return 0;
}