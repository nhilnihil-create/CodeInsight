#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  char a[n+2],b[n+2],c[n+2];
  cin >> a >> b >> c;; 
  int ans=0;
  for(int i=0;i<n;i++){
    if(a[i]!=b[i]&&b[i]!=c[i]&&c[i]!=a[i])ans+=2;
    else if(!(a[i]==b[i]&&b[i]==c[i]))ans+=1;
  }
  cout << ans;
}