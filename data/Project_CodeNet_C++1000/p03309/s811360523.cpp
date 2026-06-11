#include<stdio.h>
#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int main(){
  int n; cin>>n;
  vector<int> a(n),b(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
    b[i]=a[i]-i;
  }
  
  sort(b.begin(),b.end());
  int median=b[b.size()/2];
  long int sum=0;
  for(int i=0;i<n;i++){
    sum+=abs(b[i]-median);
  }
  
  cout<<sum;
  
  return 0;
}