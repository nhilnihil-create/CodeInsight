#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
  int a=x2+y1-y2,b=y2+x2-x1,c=x1+y1-y2,d=y1+x2-x1;
  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
}