#include <iostream>
#include <vector>
using namespace std;
int main(){
  int a,flag=0;
  cin >> a;
  vector<string> b(a);
  for(int i = 0;i<a;i++) cin >> b.at(i);
  for(int i = 0;i<a-1;i++){
    for(int j = i+1;j<a;j++){
      if(b.at(i)==b.at(j)) flag = 1;
    }
  }
  for(int i = 0;i<a-1;i++){
      string c,d;
      c = b.at(i);
      d = b.at(i+1);
    if(c.at(c.size()-1)!=d.at(0))flag = 1;
    }
  if(flag) cout << "No";
  else cout << "Yes";
}