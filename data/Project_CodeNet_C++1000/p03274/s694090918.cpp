#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
  
  int n,k; cin>>n>>k;
  vector<int>x(n);
  for(int i=0; i<n; i++){
    cin>>x.at(i);
  }
  int ans=1e9;
  for(int i=0; i+k-1<n; i++){
    ans = min(ans,abs(x.at(i))+abs(x.at(i)-x.at(i+k-1)));
    ans = min(ans,abs(x.at(i+k-1))+abs(x.at(i+k-1)-x.at(i)));
  }
  cout << ans << endl;
  
  
  
}