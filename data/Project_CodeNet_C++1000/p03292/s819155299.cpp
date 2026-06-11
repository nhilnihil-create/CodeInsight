#include <bits/stdc++.h>
using namespace std;
int main(){
  int n=3;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a,a+n);
  cout<<a[2]-a[0]<<endl;
}