#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<int>a(4,0);int x;
  for(int i=0;i<6;i++){
    cin>>x;a.at(x-1)++;
  }
  if(count(a.begin(),a.end(),1)==2&&count(a.begin(),a.end(),2)==2)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}