#include <bits/stdc++.h>
using namespace std;

int main() {
  char A,B;
  cin>>A>>B;
  if(A==B){
    cout<<'='<<endl;
    return 0;
  }
  else if(A<B){
    cout<<'<'<<endl;
    return 0;
  }
    cout<<'>'<<endl;
}
