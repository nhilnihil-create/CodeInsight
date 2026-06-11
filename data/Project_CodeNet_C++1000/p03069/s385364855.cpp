#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  int w = 0, b = 0;
  for (int i = 0; i < N; i++) {
    if (S.at(i) == '#') {
      b++;
    }
    else {
      w++; 
    }
  }
  int answer = min(N - b, N - w);
  int B = b, W = w;
  vector<int> white(N - 1);//左側の白
  vector<int> black(N - 1);//右側の黒
  for (int i = 0; i < N - 1; i++) {
    if (S.at(i) == '#') {
      b--;
    }
    else{
      w--; 
    }
    black.at(i) = B - b;
    white.at(i) = w;
    //cout << i << "   " << black.at(i) << " " << white.at(i) << endl;
    answer = min(answer, black.at(i) + white.at(i));
  }
  cout << answer << endl;
}