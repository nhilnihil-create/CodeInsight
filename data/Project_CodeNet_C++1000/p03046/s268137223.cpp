#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long m,k;cin >> m >> k;
  long long a=1;
  for (int i=0;i<m;i++) a*=2;
  if (m==0) {if (k==0) cout << "0 0" << endl; else cout << -1 << endl;}
  else if (m==1) {if (k==0) cout << "0 0 1 1" << endl; else cout << -1 << endl;}
  else {
    if (a<=k) cout << -1 << endl;
	else {
	  for (long long i=0;i<a;i++) if (i!=k) cout << i << " ";
	  cout << k << " ";
	  for (long long i=a-1;i>=0;i--) if (i!=k) cout << i << " ";
	  cout << k << endl;
	}
  }
}
