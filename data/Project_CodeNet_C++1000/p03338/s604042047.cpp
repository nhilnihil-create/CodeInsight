#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
  int N;
  cin >> N;
  vector<char> V(N);
  
  int max_count = 0;

  for (int i = 0; i < N; i++) {
    cin >> V.at(i);
  }
  
  for (int i = 0; i < N; i++) {//ある場所で切った時の左右に含まれている文字の種類
    int count = 0;
    set<char> S,T;
    for (int j = 0; j < i; j++) {
       S.insert(V.at(j));
    }
    for (int j = i; j < N; j++) {
      T.insert(V.at(j));
    }
    
    for (auto itr = S.begin(); itr != S.end(); ++itr) {
    	for (auto itt = T.begin(); itt != T.end(); ++itt) {
          	if(*itr == *itt)
              count++;
        }
    }
    max_count = max(max_count,count);
  }
  
  cout << max_count << endl;
  
 
}