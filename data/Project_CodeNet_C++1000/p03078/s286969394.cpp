#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool included[1000][1000][1000] = {false};

typedef struct {
  long long deli;
  int apos;
  int bpos;
  int cpos;
}ANS;

static bool lerger(const long long& a, const long long& b) {
  return a > b;
}
static bool ans_lerger(const ANS& a, const ANS& b) {
  return a.deli > b.deli;
}

int main(void) {
  int X, Y, Z, K;
  cin >> X >> Y >> Z >> K;
  vector <long long> A(X), B(Y), C(Z);
  for (int i = 0; i < X; i++) cin >> A[i];
  for (int i = 0; i < Y; i++) cin >> B[i];
  for (int i = 0; i < Z; i++) cin >> C[i];

  sort(A.begin(), A.end(), lerger);
  sort(B.begin(), B.end(), lerger);
  sort(C.begin(), C.end(), lerger);

  memset(included, 0, sizeof(included));

  int apos = 0, bpos = 0, cpos = 0;

  vector <ANS> ans;
  ANS top;
  top.deli = A[0] + B[0] + C[0];
  top.apos = top.bpos = top.cpos = 0;
  ans.push_back(top);
  included[0][0][0] = true;

  for (int i = 0; i < K; i++) {
    sort(ans.begin()+i, ans.end(), ans_lerger);
    ANS wk = ans[i];
    cout << wk.deli << endl;


    if (wk.apos < X-1) {
      if (!included[wk.apos+1][wk.bpos][wk.cpos]) {
        included[wk.apos+1][wk.bpos][wk.cpos] = true;
        ANS next_ans;
        next_ans = wk;
        next_ans.apos = wk.apos+1;
        next_ans.deli = A[next_ans.apos] + B[next_ans.bpos] + C[next_ans.cpos];
        ans.push_back(next_ans);
      }
    }
    if (wk.bpos < Y-1) {
      if (!included[wk.apos][wk.bpos+1][wk.cpos]) {
        included[wk.apos][wk.bpos+1][wk.cpos] = true;
        ANS next_ans;
        next_ans = wk;
        next_ans.bpos = wk.bpos+1;
        next_ans.deli = A[next_ans.apos] + B[next_ans.bpos] + C[next_ans.cpos];
        ans.push_back(next_ans);
      }
    }
    if (wk.cpos < Z-1) {
      if (!included[wk.apos][wk.bpos][wk.cpos+1]) {
        included[wk.apos][wk.bpos][wk.cpos+1] = true;
        ANS next_ans;
        next_ans = wk;
        next_ans.cpos = wk.cpos+1;
        next_ans.deli = A[next_ans.apos] + B[next_ans.bpos] + C[next_ans.cpos];
        ans.push_back(next_ans);
      }
    }
  }

  return 0;
}
