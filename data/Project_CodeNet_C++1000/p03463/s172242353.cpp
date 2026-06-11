#include <bits/stdc++.h>
using namespace std;

int main() {
 int n,A,B;
  cin>>n>>A>>B;
  int x=B-A-1;
  if(x%2==0) cout<<"Borys"<<endl;//Borysです
  else cout<<"Alice"<<endl;
}