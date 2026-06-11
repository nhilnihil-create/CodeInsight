#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
  int N;
  
  cin >> N;
  
  vector<double> a(N);
  double sum = 0.0;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    sum += a[i];
  }
  
  double ave = sum / a.size();
  
  double minv = 100000000;
  int frame_idx = N;
  for (int i = 0; i < N; i++) {
    if (minv > abs((a[i] * N) - (ave * N))) {
      minv = abs((a[i] * N) - (ave * N));
      frame_idx = i;
    }
  }
  
  cout << frame_idx << endl;
  
  return 0;
}