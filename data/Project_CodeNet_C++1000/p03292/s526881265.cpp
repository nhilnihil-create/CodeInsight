#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <climits>

#define DEBUG if(false)

using namespace std;

int main(){
  vector<int> A(3);
  cin >> A[0] >> A[1] >> A[2];
  sort(A.begin(), A.end());
  cout << abs(A[0] - A[1]) + abs(A[2] - A[1]) << endl;

  return 0;
}
