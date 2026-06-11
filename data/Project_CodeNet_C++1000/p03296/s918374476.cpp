#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  int kotae=0;
  for(int i=0;i<n-1;i++){
    if(a[i]==a[i+1]){
      a[i+1]=151515;
      kotae++;
    }
  }
  cout<<kotae<<endl;
  return 0;
}