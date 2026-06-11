#include <bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define all(a) a.begin(),a.end()
#define P pair<long long,long long>
#define double long double
using namespace std;
signed main(){
  int a,b,c,d,e;
  cin>>a>>b>>c>>d>>e;
  if((a+b)/2>=c){
    int f=min(d,e);
  int g=max(d,e);
  if(g==d){
    if(c*2<=min(a,b))
      cout<<c*2*d;
    else
  cout<<f*c*2+(g-f)*a;
    }
  else{
    if(c*e*2<=f*c*2+(g-f)*b)
      cout<<c*2*e;
    else
    cout<<f*c*2+(g-f)*b;
    }
  }
  else{
    cout<<a*d+b*e;
    }
}
