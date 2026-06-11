#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,a,c=0; cin>>n;
  while(n--){
    cin>>a;
    while(a%2==0) a/=2,c++;
  }
  cout<<c;
}