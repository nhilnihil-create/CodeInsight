#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int total =0;
  vector<int>vec(n);
  for(int i=0;i<n;i++){
    cin>>vec.at(i);
    total+=vec.at(i);
  }
  sort(vec.begin(),vec.end());
  cout<<total-vec.at(n-1)/2<<endl;
}
  
