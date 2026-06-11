#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
  
  int n,k; cin>>n>>k;
  vector<int> a(n);
  for(auto &i:a) cin>>i;
  --k; --n;
  cout << (n+k-1)/k << endl;
  
}
