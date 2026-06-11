#include<bits/stdc++.h>
using namespace std;
int main(){
  int s;
  set<int> a;
  cin>>s;
  a.insert(s);
  while(1){
    if(s%2==0) s/=2;
    else s=3*s+1;
    if(a.count(s)) break;
    else a.insert(s);
  }
  cout<<a.size()+1<<endl;
}