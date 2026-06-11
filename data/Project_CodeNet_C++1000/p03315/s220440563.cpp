#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
 

  string s;
  cin>>s;

  int num=0;
  for(int i=0;i<s.size();i++){
    if(s.at(i)=='+')
      num++;
    else if(s.at(i)=='-')
      num--;
  }

  cout<<num<<endl;

	return 0;
}