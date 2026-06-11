#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> vecs(N);
  string s;
  for (int i = 0; i < N; i++) {
    cin >> s;
    vecs.at(i) = s;
  }
  
  int M;
  cin >> M;
  vector<string> vect(M);
  string t;
  for (int j = 0; j < M; j++) {
    cin >> t;
    vect.at(j) = t;
  }
  
  vector<int> vec = {0};
  int c = 0;
  int counts = 0;
  int countt = 0;
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (vecs.at(i) == vecs.at(j)) 
        counts++;
      }
    for (int k = 0; k < M; k++) {
      if (vecs.at(i) == vect.at(k))
        countt++;
      }
    if (counts > countt) {
      c = counts - countt;
      vec.push_back(c);
    }
    else if (counts <= countt) {
      vec.push_back(0);
    }
    counts = 0;
    countt = 0;
  }
  int Ans = 0;
  for (int i = 0; i < N + 1; i++) {
    if (vec.at(i) > Ans)
      Ans = vec.at(i);
  }
  if (Ans > 0)
    cout << Ans << endl;
  else if (Ans <= 0)
    cout << 0 << endl;
}
