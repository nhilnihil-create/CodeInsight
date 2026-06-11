#include<bits/stdc++.h>
using namespace std;

int main() {
  int n,k;
  cin >> n >> k;
  n--;
  k--;
  if(n%k==0) cout << n/k;
  else cout << n/k+1;
}