#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin>>a>>b>>c;
  
  cout<<a+b+c+max({a,b,c})*9<<endl;

  return 0;
}