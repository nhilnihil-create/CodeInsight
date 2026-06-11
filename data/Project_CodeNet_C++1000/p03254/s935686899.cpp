#include<bits/stdc++.h>

using namespace std;
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  long long int n,x;
  cin>>n>>x;
  long long int f=0;
  long long int a[101];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a,a+n);
  long long int sum=0;
  int j=0;
  while(sum<x && j<n){
    f++;
    sum+=a[j];
    j++;
  }
  if(sum-x==0){
  cout<<f<<endl;
  }else{
    cout<<f-1<<endl;
  }
}