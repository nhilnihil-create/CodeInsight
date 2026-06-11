#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  vector<int> antennas(5);
  for(int i = 0; i < 5; i++){
    cin >> antennas[i];
  }
  int k;
  cin >> k;
  if(antennas[4] - antennas[0] > k){
    cout << ":(" <<endl;
    return 0;
  }
  cout << "Yay!" <<endl;
}