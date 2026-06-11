#include<bits/stdc++.h>
using namespace std;
int bigit(int n){
  int ans=0; 
  while(n!=0){
    ans+=n%10;
    n=n/10;
  }
  return ans;
}
  int main(){
    int n;
    cin>>n;
    if(n%bigit(n)==0){
      cout<<"Yes"<<endl;
    } else {
      cout<<"No"<<endl;
    }
  }