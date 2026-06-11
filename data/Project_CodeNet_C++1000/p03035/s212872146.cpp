#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int a,b;
  cin >> a >> b;
  if(a <= 5) cout << 0 << endl;
  else if(a <= 12) cout << b/2 << endl;
  else cout << b << endl;
}
