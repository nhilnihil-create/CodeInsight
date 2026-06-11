#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,mx=-1,nm=0;
  cin>>n;
  vector<int>d(n);
  for(int i=0;i<n;i++){
    cin>>d[i];
  }
  for(int i=0;i<n;i++){
    mx=max(mx,d[i]);
    nm+=d[i];
  }
  cout<<nm-mx/2<<endl;
}
  
