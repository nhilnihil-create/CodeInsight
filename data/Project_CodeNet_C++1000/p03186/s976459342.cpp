#include <bits/stdc++.h>
using namespace std;
int main(){
  int A,B,C;
  cin>>A>>B>>C;
  if(A+B>=C-1)cout<<B+C;
  else cout<<B+A+B+1;
}