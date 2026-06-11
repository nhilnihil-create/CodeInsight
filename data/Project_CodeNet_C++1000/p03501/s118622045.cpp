#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,a,b;
  cin>>n>>a>>b;
  int p;
  if(n*a>b) p=b;
  else p=n*a;
  cout<<p<<endl;
}

