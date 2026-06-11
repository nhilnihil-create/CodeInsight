#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define int long long
/*int abs(int a,int b){
  int c=max(a,b)-min(a,b);
  return c;
}*/
signed main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  double a,q=10000,w=0;
  double b[10000];
  double c=0;
  cin>>a;
  for(int i=0;i<a;i++){
    cin>>b[i];
    c+=b[i];
  }
  c/=a;
  for(int i=0;i<a;i++){
    //cout<<abs(b[i]-c)<<" "<<q<<"\n";
    if(abs(b[i]-c)<q) w=i,q=abs(b[i]-c);
  }
  cout<<w<<"\n";
}