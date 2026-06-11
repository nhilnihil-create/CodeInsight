#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int>vec(4,0);
  for(int i=0; i<6; i++){
    int K;
    cin >> K;
    vec[K-1]++;
  }
  for(int i=0; i<4; i++){
    if(vec[i] == 3){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
