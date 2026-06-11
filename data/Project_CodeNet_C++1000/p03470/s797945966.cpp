#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  int d[102],o=0;
  for(int i=0;i<n;i++){
    cin>>d[i];
  }
  sort(d,d+n);
  for(int i=1;i<n;i++){
    if(d[i]==d[i-1]){
      o++;
    }
  }
  cout<<n-o<<"\n";
  return 0;
}