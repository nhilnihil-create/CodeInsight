#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int total=0;
  vector<int>vec(n);
  for(int i=0;i<n;i++){
    cin>>vec.at(i);
    total+=vec.at(i);
  }
  sort(vec.begin(),vec.end());
  if(vec.at(n-1)<total-vec.at(n-1)){cout<<"Yes"<<endl;}
  else{cout<<"No"<<endl;}
}
