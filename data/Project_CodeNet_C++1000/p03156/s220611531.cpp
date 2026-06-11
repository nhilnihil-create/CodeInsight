#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;

  int cnt1 = 0;
  int cnt2 = 0;
  int cnt3 = 0;
  for (int i = 0; i < N; i++) {
    int P;
    cin >> P;
    if (P <= A) {
      // cout << 1 << endl;
      cnt1++;
    } else if(A + 1 <= P && P <= B) {
      // cout << 2 << endl;
      cnt2++;
    } else {
      // cout << 3 << endl;
      cnt3++;
    }
  }

  int answer = min(cnt1, min(cnt2, cnt3));

  cout << answer << endl;

}