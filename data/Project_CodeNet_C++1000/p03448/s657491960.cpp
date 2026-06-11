// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
//  cout.precision(15); cout << fixed;

int main() {
  vector<int> A(3);
  int x;
  cin >> A[0] >> A[1] >> A[2] >> x;
  int count = 0;
  loop(i,0,A[0]+1) loop(j,0,A[1]+1) loop(k,0,A[2]+1) {
    count += 500*i + 100*j + 50*k == x;
  }
  cout << count << endl;
  return 0;
}
