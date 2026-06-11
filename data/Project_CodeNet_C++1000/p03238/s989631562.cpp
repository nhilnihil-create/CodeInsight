#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N; cin >> N;
  if (N==1) cout << "Hello World" << endl;
  if (N==2) {
    int A, B; cin >> A >> B;
    cout << A + B << endl;
  }
  return 0;
}