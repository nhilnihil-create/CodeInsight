#include <iostream>
#include <string>
#include <vector>
#include<algorithm>

#define REP(i, n) for(int i = 0; i < n; ++i)
#define REPR(i, n) for(int i = n; i >= 0; --i)
#define FOR(i, m, n) for(int i = m; i < n; ++i)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;
 
int main() {
  int N, M;
  cin >> N >> M;
  int mod = (N*M) % 2;
  if (mod == 0) {
    cout << "Even" << endl;
  } else {
    cout << "Odd" << endl;
  }
}