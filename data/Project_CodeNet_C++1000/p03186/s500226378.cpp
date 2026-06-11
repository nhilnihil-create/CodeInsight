#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C;
  cin>>A>>B>>C;
  if(B>=C){
    cout<<B+C<<endl;
  }
  else{
    cout<<B*2+min(C-B,A+1)<<endl;
  }
}