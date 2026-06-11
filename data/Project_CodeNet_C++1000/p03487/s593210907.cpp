#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  map<int,int>a;
  int tmp;
  for(int i=0;i<n;i++){
    cin>>tmp;
    if(a.count(tmp))a.at(tmp)++;
    else a[tmp]=1;
  }
  int ans=0;
  for(auto num:a){
    if(num.second!=num.first){
      if(num.second>num.first){
        ans+=num.second-num.first;
      }
      else ans+=num.second;
    }
  }
  cout <<ans<<endl;
}