#include <bits/stdc++.h>
#include<vector>
using namespace std;
#define rep(i, n)        for(int i=0; i<(int)(n); ++i)
int main() {
  long long int a,b,c,d=0,f,g,h;
  cin>>a>>b>>c;
  d=max(a,max(b,c));
  cout<<a+b+c+d*9;
}