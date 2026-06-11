#include<bits/stdc++.h>
using namespace std;
#define INF -2147483647
#define mod 1000000007
signed main(){
  int a,b,c;
  int d,e=0,r=0,f=0;
  cin>>a>>b>>c;
  for(int i=0;i<a;i++){
    cin>>d;
    if(d<=b) e++;
    if(b+1<=d&&d<=c) f++;
    if(d>=c+1) r++;
  }
  //cout<<e<<f<<r<<"\n";
  cout<<min(e,min(f,r))<<"\n";
}
