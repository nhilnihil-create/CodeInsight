#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int a,b,c;
  cin>>a>>b>>c;
  if(a==b) cout<<c<<endl;
  else if(b==c) cout<<a<<endl;
  else cout<<b<<endl;
}