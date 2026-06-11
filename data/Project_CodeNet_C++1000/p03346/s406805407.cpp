#include <cstdio>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

#include <queue>

using namespace std;



int main() {
  int N;cin>>N;
  vector<int> seq(N + 1);
  seq.assign(N + 1, 0);
  vector<int> p(N);
  for(int i=0;i<N;i++) cin>>p[i];

  for(int i=0;i<N;i++) {
    int cur = p[i];
    seq[cur] = seq[cur - 1] + 1;
  }

  int out = 0;
  for(int i=0;i<=N;i++) out = max(out, seq[i]);

  cout << N-out << endl;

  return 0;
}
