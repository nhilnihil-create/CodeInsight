#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string>S(N);
  vector<int>P(N);
  for(int i=0; i<N; i++){
    cin >> S.at(i) >> P.at(i);
  }
  
  vector<pair<string, int>>SP(N);
  for(int i=0; i<N; i++){
    SP.at(i) = make_pair(S.at(i), 100-P.at(i));
  }
  
  sort(SP.begin(), SP.end());
  
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(S.at(j)==SP.at(i).first && 100-P.at(j)==SP.at(i).second){
        cout << j+1 << endl;
      }
    }
  }
}