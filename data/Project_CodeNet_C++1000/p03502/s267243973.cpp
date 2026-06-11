#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  string s=to_string(n);
  int m=0;
  for(int i=0;i<s.size();i++)m+=s.at(i)-'0';
  cout << (n%m==0?"Yes":"No") << endl;
}