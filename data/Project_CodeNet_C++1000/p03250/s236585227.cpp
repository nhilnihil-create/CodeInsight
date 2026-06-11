#include<bits/stdc++.h>
using namespace std;
int main(){
int A,B,C;
  cin>>A>>B>>C;
  int Max=max(max(A,B),C);
  cout<<9*Max+A+B+C<<endl;

return 0;
}