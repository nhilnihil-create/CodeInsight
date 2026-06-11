#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b;
  int v[5];
  int res=0;
  cin >> a >> b;
  for (int i=a; i <= b; i++) {
    int tmp = i;
    for (int j=0; j < 5; j++) {
     v[j] = tmp%10;
     tmp /= 10;    
    }
    if (v[0] == v[4] && v[1] == v[3]) ++res;
  } 
  cout << res << endl;
}