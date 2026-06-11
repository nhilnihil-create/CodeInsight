#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  int A = 0;
  int B = 0;
  int t = 0;
  int max = 0;
  int maxat = 0;
  cin >> N;
  vector<int> card(N);
  vector<bool> picked(N);
  for(int i = 0; i < N; i++){
    cin >> card.at(i);
  }
  while(t < N){
    for(int i = 0; i < N; i++){
    	if(!picked.at(i) && max < card.at(i)){
    	  max = card.at(i);
     	 maxat = i;
   		}
    }
    
    A += card.at(maxat);
    picked.at(maxat) = true;
    t++;
    if(t >= N){
      break;
    }
    max = 0;
    maxat = 0;
    for(int i = 0; i < N; i++){
    	if(!picked.at(i) && max < card.at(i)){
    	  max = card.at(i);
     	 maxat = i;
   		}
    }
    B += card.at(maxat);
    picked.at(maxat) = true;
    t++;
    
    max = 0;
    maxat = 0;
  }
  
  cout << A - B << endl;
}