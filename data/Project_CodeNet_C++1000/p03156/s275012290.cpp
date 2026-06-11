#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  cin >> N;
  cin >> A >> B;
  int a, b = 0;
  vector<int> P(N);
  for(int i = 0; i < N; i++) {
    cin >> P.at(i);
  }
  for(int i = 0; i < N; i++) {
    if(P.at(i) <= A) {
      a++;
    }
  }
  for(int i = 0; i < N; i++) {
    if(P.at(i) >= B+1) {
      b++;
    }
  }
  cout << min(a,min(b,N-a-b)) << endl;
}
