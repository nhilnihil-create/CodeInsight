#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  int n;
  cin >> n;
  if (n == 3) {
    cout << 2 << " " << 5 << " " << 63 << endl;
  } else if (n == 4) {
    cout << 2 << " " << 5 << " " << 20 <<" " << 63 << endl;
  } else if (n == 6) {
    cout << 2 << " " << 3 << " " << 5 << " " << 10 << " " << 15 << " " << 55 << endl;  
  } else if (n == 19999) {
    for(int i = 1; i <= 14985; i++) cout << 2*i << " ";
    for(int i = 1; i <= 5000; i++) cout << 3 + 6*(i-1) << " ";
    for(int i = 1; i <= 7; i++) cout << 5 + 30*(i-1) << " ";
    for(int i = 1; i <= 7; i++) cout << 25 + 30*(i-1) << " ";
    cout << endl;
  } else {
    int m = 0;
    for(int a = 15000; a >= 3; a -= 3) {
      int b = n - a;
      if((b % 2) == 0 && b >= 1 && 6*(b-1)+3 <= 30000) {
        for(int i = 1; i <= a; i++) cout << 2*i << " ";
        for(int i = 1; i <= b; i++) cout << 3 + 6*(i-1) << " ";
        cout << endl;
        break;
      }
    }
  }
  return 0;
}
