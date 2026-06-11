#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
//解説AC
int main() {
  int n;
  cin>>n;
  vector<int>c(n),s(n),f(n),a(n+1,0);
  for(int i=0;i<n;i++){
    cin>>c[i]>>s[i]>>f[i];
  }
  for(int i=0;i<n;i++){
    for(int j=i;j<n-1;j++){
      if(a[i]<s[j])a[i]=s[j];
      else if(a[i]%f[j]==0);
      else a[i]+=f[j]-a[i]%f[j];
      a[i]+=c[j];
    }
  }
  for(int i=0;i<n;i++){
    cout<<a[i]<<endl;
  }
  return 0;
}
