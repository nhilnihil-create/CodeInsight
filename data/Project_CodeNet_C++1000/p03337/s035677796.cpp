#include <bits/stdc++.h>
using namespace std;
int main(){
  int A,B;
  cin>>A>>B;
  int n,m,l;
  n=A+B;
  m=A-B;
  l=A*B;
  if(n>=max(m,l)){
    cout<<n<<endl;
  }
  else if(m>=max(n,l)){
    cout<<m<<endl;
  }
  else if(l>=max(m,n)){
    cout<<l<<endl;
  }
  return 0;
}
  