#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n,k; cin >> n >> k;
  (((n/2) + n%2) >= k) ? cout << "YES\n" : cout << "NO\n";
  return 0;
}