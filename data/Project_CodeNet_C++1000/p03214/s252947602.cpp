#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,sum=0;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
    sum+=a[i];
    a[i]*=n;
  }
  int ans=0;
  for(int i=0;i<n;i++){
    if(abs(a[ans]-sum)>abs(a[i]-sum)) ans=i;
  }
  cout<<ans<<endl;
}
