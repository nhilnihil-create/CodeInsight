#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
  int a=1;
  int n,k;
  cin >> n >> k;
  rep(i,n){
    if(a*2<a+k){
      a *=2;
    }else a +=k;
  }

  cout << a <<endl;
  return 0;
}
