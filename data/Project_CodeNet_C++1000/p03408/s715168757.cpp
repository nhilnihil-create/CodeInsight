#include <bits/stdc++.h>
using namespace std;

int main() {

  int N, M;
  cin >> N;

  vector<string> vec1(N);
  for(int i = 0; i < N; i++) {
    string str1;
    cin >> str1;
    vec1.at(i) = str1;
  }
  cin >> M;
  vector<string> vec2(M);
  for(int i = 0; i < M; i++) {
    string str2;
    cin >> str2;
    vec2.at(i) = str2;
  }
  
  int max = 0;
  for(int i = 0; i < N; i++) {
    int blNum = 0;
    string blStr = vec1.at(i);
    for(int j = 0; j < N; j++) {
      if (blStr == vec1.at(j)) {
        blNum += 1;
      }
    }
    int rdNum = 0;
    for(int k = 0; k < M; k++) {
      if (blStr == vec2.at(k)) {
        rdNum += 1;
      }
    }
    int tmpNum = 0;
    tmpNum = blNum - rdNum;
    if (tmpNum >= 0 && tmpNum > max) {
      max = tmpNum;
    }
  }

  cout << max << endl;

}
