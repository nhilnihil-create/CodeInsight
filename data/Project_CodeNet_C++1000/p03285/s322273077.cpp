#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n; cin>>n;
  for(int i=0;i*4<=n;i++) {
    for(int j=0;j*7<=n;j++) {
      if(4*i+7*j==n) {
        cout<<"Yes\n";
        return 0;
      }
    }
  }
  cout<<"No\n";
}
