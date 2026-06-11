#include <bits/stdc++.h>
using namespace std;

int main() {
  string a;
  int b=0;
  cin>>a;
  for(int i=0;i<4;i++){
    if(a.at(i)=='2'){
      b++;
    }
  }
  cout<<b<<endl;
}