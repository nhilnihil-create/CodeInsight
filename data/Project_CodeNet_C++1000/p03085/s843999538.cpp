#include <bits/stdc++.h>
using namespace std;

int main() {
  string b,a;
  cin>>b;
  if(b=="A") a="T";
  else if(b=="T") a="A";
  else if(b=="G") a="C";
  else a="G";

  cout<<a<<endl;
}