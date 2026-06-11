#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int s=0;
  int m=0;
  for(int i=0;i<n;i++){
    int p;
    cin>>p;
    s+=p;
    m=max(m,p);
  }
  cout<<s-m/2<<endl;
}