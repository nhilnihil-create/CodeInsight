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
  vector <double> A(N);
  double sum = 0;
  for (int i = 0; i < N; i++){
    cin >> A[i]; sum += A[i];
  }
  double ave = sum / N;
  
  vector < pair<double, int> > ans(N);
  for (int i = 0; i < N; i++){
    ans[i].first = abs(ave - A[i]);
    ans[i].second = i;
  }
  sort(ans.begin(), ans.end());
  cout << ans[0].second << endl;

  return 0;
}
