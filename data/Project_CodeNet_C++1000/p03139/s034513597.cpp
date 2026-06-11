#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int n,a,b;
  cin>>n>>a>>b;
  cout<<min(a,b)<<" ";
  if(a+b<=n) cout<<0<<'\n';
  else cout<<a+b-n<<'\n';
  return 0;
}
