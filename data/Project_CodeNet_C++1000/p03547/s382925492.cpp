#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  char a, b;
  cin >> a >> b;

  int cmp = (a - 'A') - (b - 'A');
  if (cmp > 0) cout << '>' << "\n";
  else if (cmp < 0) cout << '<' << "\n";
  else cout << '=' << "\n";
}
