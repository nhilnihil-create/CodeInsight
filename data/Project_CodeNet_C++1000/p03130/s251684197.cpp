#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<int> a(4);
  int N;
  for(int i=0;i<6;i++){
    cin>>N;
    a.at(N-1)++;
  }
  sort(a.begin(),a.end());
  if(a.at(0)==1 && a.at(1)==1 && a.at(2)==2)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}