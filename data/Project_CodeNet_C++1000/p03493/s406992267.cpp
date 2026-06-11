#include<bits/stdc++.h>
using namespace std;
int main(){
  string a;
  int c=0;
  cin>>a;
  if(a[0] == '1'){
    c++;
  }
  if(a[1] == '1'){
    c++;
  }
  if(a[2] == '1'){
    c++;
  }
  cout<<c<<'\n';
  return 0;
}
