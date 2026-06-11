#include <bits/stdc++.h>

using namespace std;
/*
void print(vector<int>& v)
{
  const int NO = 4;
  bool ex[5] = {false,false,false,false,false};
  int c[5]; c[NO] = 0;
  for (int i = 0; i < 8; ++i) {
    if (!ex[v.at(i)]) {
      int a = 0, b = v[i];
      for (auto j = i+1; v[j] != v.at(i); j++) {
        a ^= v.at(j);
      }
      ex[v[i]] = true;
      c[b] = a;
    }
  }
  
  if (c[0] != 0 && c[0] == c[1] && c[2] == c[1] && c[2] == c[3]) {
    for_each(v.begin(), v.end(), [](int x) {
      cout << x << " ";
    });

    for (int i = 0; i <= 4; i++) {
      if (i != NO)
      cout << i << ":" << c[i] << " ";
    }
    
    cout << endl;
  }
}
*/

int main(void) {
  int M, K; cin >> M >> K;
  int N = (1 << M);

  if (M == 0) {
    if (K == 0) {
      cout << "0 0" << endl;
    } else {
      cout << -1 << endl;
    }
  } else if (M == 1) {
    if (K == 0) {
      cout << "0 0 1 1" << endl;
    } else {
      cout << -1 << endl;
    }
  } else {
    if (K < N) {
      for (int i = 0; i < N; i++) {
        if (K != i)
          cout << i << " ";
      }
      cout << K << " ";
      for (int i = N-1; i > -1; i--) {
        if (K != i)
          cout << i << " ";
      }
      cout << K << endl;
    } else {
      cout << -1 << endl;
    }
  }
/*
  vector<int> n4;
  for (int i = 0; i < 4; i++) {
    n4.push_back(i);
    n4.push_back(i); 
  }

  do {
    print(n4);
  } while (next_permutation(n4.begin(), n4.end()));
*/
  return 0;
}