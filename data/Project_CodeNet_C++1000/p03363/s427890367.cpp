#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n;
  cin >> n;
  int a[n],b[n+1];
  b[0]=0;
  for(int i=0;i<n;i++){
    cin >> a[i];
    b[i+1]=b[i]+a[i];
  }
  sort(b,b+n+1);
  int e=1,f=0;
  for(int i=0;i<n;i++){
    if(b[i]==b[i+1])e++;
    else{
      f+=e*(e-1)/2;
      e=1;
    }
  }
  f+=e*(e-1)/2;
  cout << f;
}
