#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
vector<int>a(n);
  for(int i=0;i<n;i++){
cin>>a[i];
  }
  int s=0;
  sort(a.begin(),a.end());
  for(int i=0;i<n-1;i++){
    s+=a[i];
  }
  s+=a[n-1]/2;
  cout<<s;
}