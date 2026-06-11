#include<bits/stdc++.h>
using namespace std;

int main(){
  long long n,mn=10000000000000,mx=-1;
  cin>>n;
  vector<long long>a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<n;i++){
    mn=min(mn,a[i]);
    mx=max(mx,a[i]);
  }
  cout<<mx-mn<<endl;
}
  
