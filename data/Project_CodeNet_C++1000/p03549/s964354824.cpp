#include <bits/stdc++.h>
#include<vector>
using namespace std;
#define rep(i, n)        for(int i=0; i<(int)(n); ++i)
int main() {
  int a,b;
  int c,d=1;
  cin>>a>>b;
  a=a-b;
  rep(i,b)d*=2;
  cout<<b*d*1900+a*d*100;
}
