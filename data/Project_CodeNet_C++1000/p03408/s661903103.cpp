#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> blue(N);
  for (int i = 0; i < N; i++){
  	cin >> blue.at(i);
  }
  
  int M;
  cin >> M;
  vector<string> red(M);
  for (int j = 0; j < M; j++){
  	cin >> red.at(j);
  }
  
  int say = 0;
  for (int i = 0; i < N; i++){
  	int score =0;
    
    for (int j = 0; j < N; j++){
    if (blue.at(i) == blue.at(j)){
        	score ++;
        }
    }
    
    for (int k = 0; k < M; k++) {
    	if (blue.at(i) == red.at(k)){
        	score --;
        }
    }
    
    if (score > say){
    	say = score;
    }
    
  }
  
  cout << say;
  
  
  
}
