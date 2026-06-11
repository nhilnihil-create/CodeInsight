#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  vector<int> a(5);
  int x=0;
  
  for(int j=0; A<=B; j++) {
    int y=A;
    for(int i=0; i<5; i++) {
      a[i] = y%10;
      y/=10;
    }
    if(a[0]==a[4] && a[1]==a[3])
      x++;
    A++;
  }
  
  cout << x << endl;
}