#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<int> a(N);
  for(int i=0;i<N;i++){
    cin>>a.at(i);
  }      
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  a.push_back(0);
  a.push_back(0);
  a.push_back(0);
  int A=0,B=0;
  for(int i=0;i<N/2+1;i++){
    A+=a.at(2*i);
    B+=a.at(2*i+1);
  }
  cout<<A-B<<endl;
}