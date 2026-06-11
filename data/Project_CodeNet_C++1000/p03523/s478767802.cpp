#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;cin >> s;
  vector<string> sa(16);
  for (int i=0;i<16;i++) {
    string x="";
	if (i & 8) x+='A';
	x+="KIH";
	if (i & 4) x+='A';
	x+='B';
	if (i & 2) x+='A';
	x+='R';
	if (i & 1) x+='A';
	sa[i]=x;
  }
  long long r=0;
  for (int i=0;i<16;i++) if (s==sa[i]) r=1;
  if (r) cout << "YES" << endl;
  else cout << "NO" << endl;
  
  
  
}