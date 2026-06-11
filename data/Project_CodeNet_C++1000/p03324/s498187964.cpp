#include <bits/stdc++.h>
using namespace std;

int main() {
	int d,n; cin >> d >> n;
	if(d==0) {
      if(n==100) cout << 101 << endl;
      else cout << n;
    }
	else if(d==1) {
      if(n==100) cout << 101*100 << endl;
      else cout << n*100 << endl;
    }
	else {
      if(n==100) cout << 101*10000 << endl;
      else cout << 10000*n << endl;
    }
}