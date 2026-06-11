#include <bits/stdc++.h>
using namespace std;
bool is_prime(int x){
  if(x<=1) return false;
  for(int i=2;i*i<=x;i++)
  if(x%i==0) return false;
  return true;
}
int main() {
  int n;
  cin>>n;
  vector<int>a;
  for(int i=2;i<=n;i++){
    if(is_prime(i))a.push_back(i);
  }
  int kotae=0;
  if(a.size()<=3){
    cout<<0<<endl;
    return 0;
  }
  for(int i=0;i<a.size()-2;i++){
    for(int j=i+1;j<a.size()-1;j++){
      for(int k=j+1;k<a.size();k++){
        //cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<endl;
        if(a[i]*a[j]*a[k]%2==1&&n>=a[i]*a[j]*a[k]){
          //cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<endl;
          kotae++;
        }
      }
    }
  }
  for(int i=0;i<a.size()-1;i++){
    for(int j=i+1;j<a.size();j++){
      if(a[i]*a[i]*a[i]*a[j]%2==1&&n>=a[i]*a[i]*a[i]*a[j]){
        //cout<<a[i]<<" "<<a[j]<<endl;
        kotae++;
      }
    }
  }
  cout<<kotae<<endl;
  return 0;
}