#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t n,m,gcd;
  string s,t;
  cin >> n >> m >> s >> t;
  {int64_t g=max(n,m),l=min(n,m);gcd=l;
   while(g%l!=0){
     gcd=g%l;
     g=l;
     l=gcd;
   }
  }
  bool ok=true;
  for(int i=0;i<gcd;i++){
    if(s.at((n/gcd)*i)!=t.at((m/gcd)*i))
      ok=false;
  }
  cout << (ok?gcd*n/gcd*m/gcd:-1) << endl;
  return 0;
}