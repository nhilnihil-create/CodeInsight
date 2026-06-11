#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
 
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int a,b;
  cin>>a>>b;
  
  if(a%2==1) a++;
  if(b<=a/2) cout<<"YES"<<'\n';
  else cout<<"NO"<<'\n';
}
