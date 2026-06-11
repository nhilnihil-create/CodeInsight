#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  vector<int>a(n),b(n);
  for(int i=0;i<n;i++){
    cin>>a.at(i);
    b.at(i)=a.at(i);
  }
  sort(a.begin(),a.end());
  for(int i=0;i<n;i++){
    if(b.at(i)<a.at(n/2)){
      cout <<a.at(n/2)<<endl;
    }
    else if(b.at(i)>=a.at(n/2)){
      cout <<a.at(n/2-1)<<endl;
    }
  }
}