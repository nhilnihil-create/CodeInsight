#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> card(N);
  for (int i = 0; i < N; i++){
  	cin >> card.at(i);
  }
  
  int Alice = 0, Bob = 0;
  
  for (int i = 0; i < N; i++){
  	if (i % 2 == 0){
    	int score = 0;
      	for (int j = 0; j < N; j++){
        	if (card.at(j) > score){
            	int back;
              	back = score;
              	score = card.at(j);
              	card.at(j) = back;
            }
        }
      	Alice += score;
    }
    
    if (i % 2 == 1){
    	int score = 0;
      	for (int j = 0; j < N; j++){
        	if (card.at(j) > score){
            	int back;
              	back = score;
              	score = card.at(j);
              	card.at(j) = back;
            }
        }
      	Bob += score;
    }
  }
  
  cout << Alice - Bob;
  
  
}