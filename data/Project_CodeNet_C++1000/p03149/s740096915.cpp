#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  vector<int> N(10, 0);
  for(int i=0;i<4;i++){ cin>>a;N.at(a)++; }
  if(N[1]&&N[9]&&N[7]&&N[4])cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}