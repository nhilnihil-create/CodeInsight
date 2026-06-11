#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
int main() {
  string a; cin >> a;
  bool ans = false;
  if(a[0] == a[1] && a[1] == a[2] ) ans = true;
  if(a[1] == a[2] && a[2] == a[3] ) ans = true;
  
  cout << (ans ? "Yes" : "No") << endl;
	return 0;
}

