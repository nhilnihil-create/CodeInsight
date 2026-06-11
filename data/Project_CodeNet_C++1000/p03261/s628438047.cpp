#include <iostream>
#include <vector>
#include <map>
 
using namespace std;
 
int main(void) {
  int N;
  cin >> N;
  vector<string> W(N);
  map<string, int> S;

  for(int i = 0; i < N; i++){
    cin >> W[i];
  }
  for (int i = 0; i < N - 1; i++) {
    if (W[i][W[i].size() - 1] != W[i + 1][0]) {
      cout << "No" << endl;
      return 0;
    }
  }
  for (int i = 0; i < N; i++) {
    S[W[i]]++;
    if(S[W[i]] == 2){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;

  return 0;
}