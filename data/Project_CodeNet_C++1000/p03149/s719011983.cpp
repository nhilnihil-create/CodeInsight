#include <bits/stdc++.h>
using namespace std;

int main() {
  vector <int> a(4);
  for(int i=0;i<4;i++){
    cin>>a.at(i);
  }
  sort(a.rbegin(),a.rend());
  if(a.at(0)==9&&a.at(1)==7&&a.at(2)==4&&a.at(3)==1){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
}