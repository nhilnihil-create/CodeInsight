#include<bits/stdc++.h>
using namespace std;
int main(){
  int A,B,C;
  cin>>A>>B>>C;
  int tmp=B/A;
  if(tmp<C)cout<<B/A<<endl;
  else cout<<C<<endl;
}