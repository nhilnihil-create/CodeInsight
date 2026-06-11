#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (ll i = m; i < (n); i++)

using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;


int main() {
  int a,b,c,d;
  cin >> a >>b>>c>>d;
  if(a+b>c+d) cout << "Left" << endl;
  if(a+b==c+d) cout << "Balanced" << endl;
  if(a+b<c+d) cout << "Right" << endl;
  
}
      