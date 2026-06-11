#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  long long n,a,b,c,d,e,f;
  cin >>n>>a>>b>>c>>d>>e;
  f=min(min(a,b),min(c,d));
  f=min(f,e);
  if(f==1){
    cout << n/f+4;
    return 0;
  }
  cout << n/f+5;
}