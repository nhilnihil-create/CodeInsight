#include <bits/stdc++.h>
using namespace std;

int main() {
  int q,w,e,r;
  cin>>q>>w>>e>>r;
  int a=e-q,b=r-w;
  cout<<e-b<<" "<<r+a<<" "<<q-b<<" "<<w+a<<endl;
}