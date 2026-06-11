#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
  int q,w,e,r;
  cin >> q >> w >> e >> r;
  
  cout << min(q,w) + min(e,r) << endl;
	return 0;
}
