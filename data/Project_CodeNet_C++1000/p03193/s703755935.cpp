#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main () {
  int N , H , W;
  cin >> N >> H >> W;
  int answer = 0;
  rep(i, N){
    int A , B;
    cin >> A >> B;
    if(A >= H && B >= W){
      answer++;
    }
  }
  cout << answer << endl;
  return 0;
}
