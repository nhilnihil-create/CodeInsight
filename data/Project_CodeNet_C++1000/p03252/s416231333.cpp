#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

string S, T;

bool same_idxs(vector<int>* v1, vector<int>* v2) {
  if (v1->size() != v2->size()) {
    return false;
  }

  for (int i = 0; i < v1->size(); i++) {
    if ((*v1)[i] != (*v2)[i]) {
      return false;
    }
  }

  return true;
}

int main() {
  cin >> S >> T;

  char R1[0x100], R2[0x100];
  for (int i = 0; i < 0xff; i++)
    R1[i] = R2[i] = -1;

  for (int i = 0; i < S.size(); i++) {
    if (R1[S[i]] < 0) {
      R1[S[i]] = T[i];
    } else if (R1[S[i]] != T[i]) {
      cout << "No" << endl;
      return 0;
    }
    if (R2[T[i]] < 0) {
      R2[T[i]] = S[i];
    } else if (R2[T[i]] != S[i]) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}
