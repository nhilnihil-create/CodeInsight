#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string a, b, c;
  cin >> a >> b >> c;
  int m = 0;
  for (int i = 0; i < n; ++i) {
    string d = "";//string(a[i]) + string(b[i]) + string(c[i]);
    d+=a[i]; d+=b[i]; d+=c[i];
    sort(d.begin(), d.end());
    if (d[0] == d[2])
      continue;
    else if (d[0] == d[1] || d[1] == d[2]) {
    	m++;
    }
	else
      m += 2;
  }
  
  cout << m << endl;
  return 0;
}
