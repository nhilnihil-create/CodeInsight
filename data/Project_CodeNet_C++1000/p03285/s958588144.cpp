#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  bool ans = false;
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      if (i*4+j*7==n) ans=true;
    }
  }
  cout<<(ans ? "Yes":"No")<<endl;
}