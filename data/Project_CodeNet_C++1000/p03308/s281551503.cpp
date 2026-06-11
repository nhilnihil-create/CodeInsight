#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,a,ma,mi; cin>>n>>a;
  ma=a; mi=a;
  for(int i=1; i<n; i++){
    cin>>a;
    ma=max(ma,a),mi=min(mi,a);
  }
  cout<<ma-mi;
}