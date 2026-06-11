#include <bits/stdc++.h>
#define rep(i, e, n) for (int i = e; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const ll inf=1000000000007;

int main() {
  char b;
  cin >> b;
  if(b=='A') cout << 'T' << endl;
  if(b=='T') cout << 'A' << endl;
  if(b=='G') cout << 'C' << endl;
  if(b=='C') cout << 'G' << endl;

  return 0;
}