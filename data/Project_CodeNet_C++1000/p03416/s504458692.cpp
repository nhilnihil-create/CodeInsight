#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b,s=0;
  cin >> a >> b;
  for (int i=a; i<b+1; i++) {
    if (i/10000==i%10 && i/1000-i/10000*10==i/10-i/100*10) {
      s++;
    }
  }
  cout << s << endl;
}