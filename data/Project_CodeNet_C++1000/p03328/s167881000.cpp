#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int keisan(int x) {
  int ret_val=0;
  rep_eq(i,1,x) {
    ret_val+=i;
  }
  return ret_val;
}

int main(){
  int a,b; cin >>a >>b;
  int ans=keisan(b-a)-b;
  cout <<ans <<endl;
  return 0;
}
