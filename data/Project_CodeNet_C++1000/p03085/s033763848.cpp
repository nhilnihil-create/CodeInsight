#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;



int main() {
  char b;cin >> b;
  char ans;
  if(b == 'A') ans = 'T';
  if(b == 'T') ans = 'A';
  if(b == 'C') ans = 'G';
  if(b == 'G') ans = 'C';
  cout << ans << endl;

	return 0;
}

