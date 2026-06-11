#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,a,b,s=0; cin>>n>>a>>b;
  for(int i=1; i<=n; i++){
    int c=0;
    for(int j=i; j>0; j/=10) c+=j%10;
    if(a<=c&&c<=b) s+=i;
  }
  cout<<s;
}