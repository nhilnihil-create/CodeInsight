#include <bits/stdc++.h>
using namespace std;

int main() {
  string a;
  cin>>a;
  int d=a.size();
  
  if(d==2){
    cout<<a<<endl;
  }
  else{
    reverse(a.begin(),a.end());
    cout<<a<<endl;
  }
}