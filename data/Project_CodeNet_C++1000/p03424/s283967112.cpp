#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  string s;
  int p=0,w=0,g=0,y=0;
  for (int i=0;i<n;i++){
    cin >> s;
  	if(s=="P") p++;
  	if(s=="W") w++;
  	if(s=="G") g++;
  	if(s=="Y") y++;
  }
  if(p>0 && w>0 && g>0 && y>0) cout << "Four" << endl; else cout << "Three" << endl;
}
