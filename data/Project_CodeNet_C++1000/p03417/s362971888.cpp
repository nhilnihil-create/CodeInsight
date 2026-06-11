#include <bits/stdc++.h>
using namespace std;
signed main(){
  long long n , m , a;
  cin>>n>>m;
  if(n == 1 && m == 1){
    a=1;
  } else if(n == 1 || m == 1){
    a=max(n,m)-2;
  } else {
    a = (n-2)*(m-2);
  }
  cout<<a<<endl;
  return(0);
}
