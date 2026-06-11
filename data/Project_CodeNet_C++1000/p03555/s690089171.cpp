#include <bits/stdc++.h>
using namespace std;

int main() {
  string C1,C2;
  cin>>C1>>C2;
  if(C1.at(0)==C2.at(2)&&C1.at(1)==C2.at(1)&&C1.at(2)==C2.at(0))
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
}