#include <bits/stdc++.h>
using namespace std;

int main(){
  map<int,int> A;
  for(int i=0;i<3;i++){
    int a,b;
    cin>>a>>b;
    A[a]++;
    A[b]++;
  }
  for(pair<int,int> i:A){
    if(i.second==3){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;
}