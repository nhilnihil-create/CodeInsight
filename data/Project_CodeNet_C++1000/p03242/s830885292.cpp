#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin>>S;
  for(char &c:S)
    if(c=='1')
      c='9';
    else
      c='1';
  cout<<S<<endl;
}
