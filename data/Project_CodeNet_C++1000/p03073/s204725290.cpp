#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int c=0,d=0;
  for(int i=0,l=s.size();i<l;i++){
    if((i%2==0&&s.at(i)!='0')||(i%2==1&&s.at(i)!='1'))
      c++;
    if((i%2==0&&s.at(i)!='1')||(i%2==1&&s.at(i)!='0'))
      d++;
  }
  cout << min(c,d) << endl;
  return 0;
}