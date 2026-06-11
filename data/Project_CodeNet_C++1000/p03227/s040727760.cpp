#include<bits/stdc++.h>
using namespace std;
signed main(){
  string a;
cin>>a;
  if(a.size()==2) cout<<a;
  else {
    swap(a[0],a[2]);
    cout<<a;
  }
  cout<<"\n";
}