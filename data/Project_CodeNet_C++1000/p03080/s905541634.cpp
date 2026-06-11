#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define int long long
int abs(int a,int b){
  int c=max(a,b)-min(a,b);
  return c;
}
signed main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
int a,b=0,r=0;
  string s;
  cin>>a>>s;
  for(int i=0;i<a;i++){
    if(s[i]=='R') r++;
    else b++;
  }
  if(r>b) cout<<"Yes";
  else cout<<"No";
}