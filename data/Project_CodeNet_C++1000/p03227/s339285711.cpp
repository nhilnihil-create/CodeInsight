#include <bits/stdc++.h>
using namespace std;
int main(){
  string a;
  cin>>a;
  if(a.size()==3){
    reverse(a.begin(),a.end());
    cout<<a<<endl;
  }
  else cout<< a<<endl;
}