#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  vector<int>a(5);
  int k;
  rep(i,5)cin>>a[i];
  cin>>k;
  
  sort(a.begin(),a.end());
  if(a[4]-a[0]<=k)cout<<"Yay!"<<endl;
  else cout<<":("<<endl;

  return 0;
}