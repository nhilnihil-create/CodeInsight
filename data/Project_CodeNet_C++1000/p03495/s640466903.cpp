#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k,a[200010]={},b[200010]={};
  cin>>n>>k;
  for(int i=0;i<n;++i)cin>>a[i];

  sort(a,a+n);

  int j=0;
  for(int i=0;i<n;++i){
    if(a[i]==a[i+1])b[j]++;
    else{
      b[j]++;
      j++;
    }
  }

  sort(b,b+j);
  reverse(b,b+j);

  int ans=0;
  while(j>k){
    ans+=b[--j];
  }
  cout << ans << endl;

  return 0;
}
//xueleiさん