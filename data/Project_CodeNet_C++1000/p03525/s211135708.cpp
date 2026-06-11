#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>

using namespace std;

const int nmax = 1e9 + 7;
typedef long long ll;

int main(){
  int N; cin >> N;

  vector <int> D(N);
  for (int i = 0; i < N; i++) cin >> D[i];
  sort(D.begin(), D.end(), greater<int>());

  bool flag = true;
  for (int i = 0; i < N; i++){
    if (D[i] != 12){
      if (flag == true){
        flag = false;
      }else{
        flag = true;
        D[i] = 24 - D[i];
      }
    }
  }
  D.push_back(0); D.push_back(24);

  sort(D.begin(), D.end(), greater<int>());

  int ans = 24;
  for (int i = 0; i < N + 1; i++){
    int A = D[i] - D[i + 1];
    if (ans > A){
      ans = A;
    }
  }
  cout << ans << endl;

  return 0;
}
