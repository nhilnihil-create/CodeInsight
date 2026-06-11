#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  int data[n+1][3];
  for (int j = 0; j < 3; j++)
    data[0][j] = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 3; j++)
      cin >> data[i+1][j];
  bool count = true;
  for (int i = 0; i < n; i++){
    int dt = data[i+1][0] -data[i][0];
    int dl = abs(data[i+1][1] -data[i][1]) + abs(data[i+1][2] -data[i][2]); 
    if (dt < dl) count = false;
    if ((dt-dl)%2 != 0) count = false;
    if(!count) break;
  }
  if (count) cout << "Yes" << endl;
  else cout << "No" << endl;
}