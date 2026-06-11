#include <bits/stdc++.h>
using namespace std;
signed main(){
  int n=0;
  string c="\0";
  cin>>c;
  while(c[n+8] != '\0'){
    cout<<c[n];
    n++;
  }
  cout<<endl;
  return(0);
}
  