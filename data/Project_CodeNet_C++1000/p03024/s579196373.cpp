#include<bits/stdc++.h>
using namespace std;
int main(){
  string a;
  int b=0;
  cin>>a;
  for(int i=0;i<a.size();i++){
    if(a[i]=='x') b++;
  }
  if(b>=8) cout<<"NO";
  else cout<<"YES";
  cout<<"\n";
}