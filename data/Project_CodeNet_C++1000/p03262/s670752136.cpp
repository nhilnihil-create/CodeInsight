#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
  
  int n,x; cin>>n>>x;
  vector<int>a(n);
  for(auto &i:a)cin>>i;
  a.push_back(x);
  sort(a.begin(),a.end());
  vector<int> b(n);
  for(int i=0; i<n; i++){
    b.at(i) = a.at(i+1)-a.at(i);
  }
  int ans = b.at(0);
  for(int i=0; i<n-1; i++){
    ans = gcd(ans,b.at(i+1));
  }
  cout << ans << endl;
}

