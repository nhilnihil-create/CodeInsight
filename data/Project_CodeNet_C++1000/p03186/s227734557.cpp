#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C;
  cin>>A>>B>>C;
  if(A+B<C){
    cout<<A+B+B+1<<endl;
  }
  else{
    cout<<B+C<<endl;
  }
}
