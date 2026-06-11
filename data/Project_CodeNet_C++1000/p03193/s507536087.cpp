#include <bits/stdc++.h>
#define rep(i,m,n) for(int i=m;i<n;i++)
#define co(n) cout<<n<<endl
using namespace std;

int main(){ 
  int a=0,b=0,c=0,n,x,y,m;
  cin>>n>>x>>y;
  rep(i,0,n){
    cin>>a>>b;
    if(a>=x && b>=y) c++;
  }
  co(c);
  
  
  return 0;
}