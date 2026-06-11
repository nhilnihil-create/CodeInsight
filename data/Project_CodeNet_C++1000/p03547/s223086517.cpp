#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  char x,y;
  cin >>x >>y;
  if(x>y) cout << ">" << endl;
  if(x==y) cout << "=" << endl;
  if(x<y) cout << "<" << endl;
  return 0;
}
