#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,ans=0;
  cin >>n;
  string a,b,c;
  cin >>a >>b >>c;
  for(int i=0;i<n;i++){
    if(a[i]!=b[i] && (b[i]!=c[i] &&a[i]!=c[i]))ans+=2;
    else if (a[i]!=b[i] || (b[i]!=c[i] || a[i]!=c[i]))ans+=1;
    cerr<<ans<<endl;
  }
  cout <<ans <<endl;
}