#include <bits/stdc++.h>
using namespace std;
int n,i,a[10],b=1;
int main(){
  for(cin>>n;i<n;i++){
    cin>>a[i];
    b*=(a[i]&1?1:2);
  }
  cout<<pow(3,n)-b<<endl;
}