#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a;
  cin>>n>>a;
  int g=a;
  int l=a;
  for(int i=1;i<n;i++){
    cin>>a;
    g=max(g,a);
    l=min(l,a);
  }
  cout<<g-l<<endl;
}