#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,d,x,a[101];
  cin>>n>>d>>x;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  int num=0;
  for(int i=1;i<=n;i++){
    num+=(d-1)/a[i]+1;
  }
  cout<<num+x<<endl;
}