#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(n) n.begin(),n.end()
const ll MOD=1000000007;
const long double PI=3.14159265358979;

int main() {
  ll x1,y1,x2,y2,dx,dy;
  cin>>x1>>y1>>x2>>y2;
  dx=x1-x2;
  dy=y1-y2;
  cout<<x2+dy<<" "<<y2-dx<<" "<<x1+dy<<" "<<y1-dx;
}
