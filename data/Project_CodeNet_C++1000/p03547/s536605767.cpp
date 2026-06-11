#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
  char a,b;
  cin >> a >> b;
  (int)(a -= 'A');
  (int)(b -= 'A');
  
  if(a > b) cout << ">" << endl;
  if(a == b) cout << "=" << endl;
  if(a < b) cout << "<" << endl;
	return 0;
}
