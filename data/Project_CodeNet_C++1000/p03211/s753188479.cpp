#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  int a=0;
  cin >> str;
  a=str.size();
  
  vector<char> b(a);  
  for (int i=0;i<a;i++){
  b.at(i)=str.at(i);
  }
  vector<int> c(a-2);
  vector<int> d(a-2);
  for (int i=0;i<a-2;i++){
  c.at(i)=(b.at(i)-'0')*100+(b.at(i+1)-'0')*10+(b.at(i+2)-'0');
  d.at(i)=max(753,c.at(i))-min(753,c.at(i));
  }
  sort(d.begin(),d.end());
  cout << d.at(0) << endl;
}