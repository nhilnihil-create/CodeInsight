#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,C;
  cin>>A>>B>>C;
  if(A>=B && A>=C && B>=C){
    cout<<A-C<<endl;
  }
  else if(B>=A && B>=C && C<=A){
    cout<<B-C<<endl;
  }
  else if(C>=A && B<=C && B<=A){
    cout<<C-B<<endl;
  }
  else if(C>=A && B<=A && B<=C){
    cout<<A-B<<endl;
  }
  else if(C<=B && B>=A && C>=A){
    cout<<B-A<<endl;
  }
  else if(C>=A && B<=C && A<=B){
    cout<<C-A<<endl;
  }
}
