#include <bits/stdc++.h>
#define rep(i, e, n) for (int i = e; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const ll inf=1000000000007;

int main(){
  int a,b,t;
  cin >> a >> b >> t;
  int val=(t+0.5)/a;
  cout << val*b << endl;
  return 0;
}