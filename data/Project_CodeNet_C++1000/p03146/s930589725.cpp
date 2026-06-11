#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[1001001]; cin>>a[0];
  for(int i=1; i<=1001001; i++){
    if(a[i-1]%2) a[i]=3*a[i-1]+1;
    else a[i]=a[i-1]/2;
    for(int j=0; j<i; j++){
      if(a[i]==a[j]){cout<<i+1; return 0;}
    }
  }
}