#include <bits/stdc++.h>
using namespace std;
 




int main() {

  int n;
  cin>>n;

  int64_t out;
  cin>>out;
  for(int i=0;i<n-1;i++){
    int64_t wk;
    cin>>wk;

    out = gcd(out,wk);
  }

  cout<<out<<endl;

  return 0;
}