#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int n,m,x;
  cin >> n >> m >> x;
  int a[m];
  
  int b[n];
  for(int i = 0; i < n; i++) {
    b[i] = 0;
  }

  for(int i = 0; i < m; i++) {
    cin >> a[i];
    b[a[i]] = 1;
  }
  int start = 0;
  int goal = 0;

  for(int i = 0; i < n; i++) {
    if(x < i) start += b[i];
    else goal += b[i];
  }
  cout << min(start, goal) << endl;
  return 0;
}