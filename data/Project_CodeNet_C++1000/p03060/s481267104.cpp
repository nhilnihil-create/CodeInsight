#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int>V(n);
  for(int i=0;i<n;i++){
    cin>>V.at(i);
  }
  vector<int>C(n);
  for(int i=0;i<n;i++){
    cin>>C.at(i);
  }
  int ans=0;
  for(int i=0;i<n;i++){
    if(V.at(i)>C.at(i)){
      ans+=V.at(i)-C.at(i);
    }
  }
  cout<<ans<<endl;
}
