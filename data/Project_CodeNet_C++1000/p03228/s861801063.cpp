#include <iostream>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>
#include <set>
#include <random>
using namespace std;

int main() {
  int K, A[2];
  cin >> A[0] >> A[1] >> K;
  for (int i = 0; i < K; i++) {
	  if (A[i % 2] == 1) {
		  A[i % 2]--;
		}
	  A[i % 2]       /= 2;
	  A[(i + 1) % 2] += A[i % 2];
	}
  cout << A[0] << " " << A[1] << endl;
  return 0;
}
