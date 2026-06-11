#include <bits/stdc++.h>
using namespace std;

int sum(int n) {
  int ans;
  for(int i=1; i<=n; i++) ans += i;
  return ans;
}

int main() {
  int a,b; cin>>a>>b;
  int d = sum(b-a);
  cout<<d-b;
}