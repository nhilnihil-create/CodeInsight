#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long n,ans,k;
  ans=0;
  cin>>n;
  vector<long> vec(n);
  vector<long> ko(0);
  for(long i=0; i<n; i++){
    cin>>vec.at(i);
  }
  for(long i=1; i<n; i++){
    vec.at(i)=vec.at(i-1)+vec.at(i);
  }
  for(long i=0; i<n; i++){
    ko.push_back(vec.at(i));
    if(vec.at(i)==0){
      ans++;
    }
  }
  sort(ko.begin(),ko.end());
  k=1;
  for(int i=1; i<n; i++){
    if(ko.at(i)==ko.at(i-1)){
      k++;
    }
    else{
      if(k>1){
        ans=ans+k*(k-1)/2;
        k=1;
      }
    }
  }
  if(k>1){
    ans=ans+k*(k-1)/2;
  }
  cout<<ans;
}