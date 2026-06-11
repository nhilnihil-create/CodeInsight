#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int a,b;
  cin >> a >> b;
  int c,d,e;
  c = a+b;
  d = a-b;
  e = a*b;

  cout << max(c,max(d,e));

}
