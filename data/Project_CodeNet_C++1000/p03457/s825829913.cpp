#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<tuple<int, int, int>> p(N);
  for (int i=0; i<N; i++) {
  int t, x, y;
  cin >> t >> x >> y;
  p.at(i) = make_tuple(t, x, y);
  }
  
  int count = 0;
  for (tuple<int, int, int> tup : p) {
    int t, x, y;
    int a, b, c;
    tie(t, x, y) = tup;
    count++;
    
    if (count == 1) {
      if (t < x+y) {
        cout << "No" << endl;
        goto SKIP;
      }
      else {
        a=t, b=x, c=y;
      }
    }
    
    else { 
      if (x-b >= 0 && y-c >= 0) {
        if (t-a < x-b + y-c) {
          cout << "No" << endl;
          goto SKIP;
        }
        else if (t-a >= x-b + y-c && (t-a-x-b+y-c)%2 != 0) {
          cout << "No" << endl;
          goto SKIP;
        }
        else a=t, b=x, c=y;
      }
      
      if (x-b >= 0 && y-c < 0) {
        if (t-a < x-b + c-y) {
          cout << "No" << endl;
          goto SKIP;
        }
        else if (t-a >= x-b + c-y && (t-a-x-b+c-y)%2 != 0) {
          cout << "No" << endl;
          goto SKIP;
        }
        else a=t, b=x, c=y;
      }
      
      if (x-b < 0 && y-c < 0) {
        if (t-a < b-x + c-y) {
          cout << "No" << endl;
          goto SKIP;
        }
        else if (t-a >= b-x + c-y && (t-a-b-x+c-y)%2 != 0) {
          cout << "No" << endl;
          goto SKIP;
        }
        else a=t, b=x, c=y;
      }
    } 
  }
 
  cout << "Yes" << endl;
  
  SKIP:
  return 0;
}