#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int A, B;
  cin >> A >> B;
  vector <int> score(N);
  int t1 = 0;
  int t2 = 0;
  int t3 = 0;
  for(int i = 0; i < N; i++) {
    cin >> score.at(i);
  }
  for (int i = 0; i < N; i++) {
    int s = score.at(i);
    if (s <= A) {
      t1++;
    }
    else if (s <= B) {
      t2++;
    }
    else {
      t3++;
    }
  }
  cout << min(min(t1, t2), t3) << endl;
  return 0;
}