#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;

int main() {
  int a,b,c;
  cin>>a>>b>>c;
  
  int d,e,f;
  d=abs(a-b);
  e=abs(b-c);
  f=abs(c-a);
  
  cout<<min({d+e,e+f,f+d});
  
  return 0;
}