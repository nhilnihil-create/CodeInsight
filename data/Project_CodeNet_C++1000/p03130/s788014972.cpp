#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  int town[4] = {0,0,0,0};
  for(int i=0;i<3;i++){
    cin >> a >> b;
    town[a-1]++;
    town[b-1]++;
  }
  bool can = (town[0]!=3)&&(town[1]!=3)&&(town[2]!=3)&&(town[3]!=3);
  cout << (can ? "YES" : "NO") << endl;
  return 0;
}