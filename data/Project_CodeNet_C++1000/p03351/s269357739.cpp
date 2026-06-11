#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const ll MOD = 1e9+7;

int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int ab = max(a-b, b-a);
  int ac = max(a-c, c-a);
  int bc = max(c-b, b-c);
  if(d>=ac) cout << "Yes" << endl;
  else if(d>=ab&&d>=bc) cout << "Yes" << endl;
  else  cout << "No" << endl;

}