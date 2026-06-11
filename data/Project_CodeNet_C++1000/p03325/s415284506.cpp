#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int num=0;
  for(int i=0;i<n;i++){
    if(a[i]%2!=0){
      continue;
    }
    while(a[i]%2==0){
      num++;
      a[i]/=2;
    }
  }
  cout<<num<<endl;
}