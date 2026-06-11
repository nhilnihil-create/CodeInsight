#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n,ans=0,MIN=1e10;
  cin >> n;
  long long a[n],b[n];
  bool f=true;
  for(int i=0;i<n;i++){
    cin >> a[i] >> b[i];
    ans+=a[i];
    if(a[i]>b[i]) MIN=min(MIN,b[i]);
    if(a[i]!=b[i]) f=false;
  }
  if(f){
    cout << 0 << endl;
    return 0;
  }
  cout << ans-MIN << endl;
  return 0;
}