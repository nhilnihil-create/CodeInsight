#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
 
  string s;
  cin>>s;

  int w;
  cin>>w;


  for(int i=0;i<s.size();i+=w){
    cout<<s.at(i);
  }
  cout<<endl;

	return 0;
}