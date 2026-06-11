#include <bits/stdc++.h>
using namespace std;
int main () {
  vector<int> data(4);
  for(int i = 0; i < 4; i++)cin >> data.at(i);
  sort(data.begin(), data.end());
  int A[4] = {1, 4, 7, 9};
  for(int i = 0; i < 4; i++){
    if(A[i] != data.at(i)){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
