#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  string ans="No";
  for(int i=0;i<=15;i++){
    int x=n-i*7;
    if(x>=0 && x%4==0) ans="Yes";
  }
  cout<<ans<<endl;
}
